#pragma once

#include <Estimate.h>
#include <sys/mman.h>
#include "TestCase.h"
#include "SumGene.h"

class SumGeneTestCase : public entw::TestCase {
public:
  void include() override {
    test("test", [](entw::Expect &expect) {
      float a = 3;
      float b = 12;

      const auto sumGene = all::SumGene();

      const auto code = sumGene.code();

      std::size_t required_memory_size = all::estimate_memory_size(code.size());

      auto *mem = (uint8_t *) mmap(nullptr,
                                   required_memory_size,
                                   PROT_READ | PROT_WRITE | PROT_EXEC,
                                   MAP_PRIVATE | MAP_ANONYMOUS,
                                   -1,
                                   0);

      if (mem == MAP_FAILED) {
        std::cerr << "Can't allocate memory\n";
        std::exit(1);
      }

      for (size_t i = 0; i < code.size(); ++i) {
        mem[i] = code[i];
      }

      float (*func)(float, float);

      func = (float (*)(float, float)) mem;

      func(a, b);

      expect(func(a, b)).toEqual(15);
    });
  };
};