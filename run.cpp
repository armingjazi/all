#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/mman.h>

std::vector<uint8_t> sumCode() {
   std::vector<uint8_t> machine_code {
     0x55,
     0x48, 0x89, 0xe5,
     0xf3, 0x0f, 0x11, 0x45, 0xfc,
     0xf3, 0x0f, 0x11, 0x4d, 0xf8,
     0xf3, 0x0f, 0x10, 0x45, 0xfc,
     0xf3, 0x0f, 0x58, 0x45, 0xf8,
     0x5d,
     0xc3,
   };
   return machine_code;
}

std::size_t estimate_memory_size(size_t machine_code_size) {
     size_t page_size_multiple = sysconf(_SC_PAGE_SIZE);     // Get the machine page size
     size_t factor = 1, required_memory_size;

     for(;;) {
         required_memory_size = factor * page_size_multiple;
         if(machine_code_size <= required_memory_size) break;
         factor++;
     }
     return required_memory_size;
}

void show_machine_code(const std::vector<uint8_t> &machine_code) {
    int konto = 0;
    std::cout << "\nMachine code generated:\n";
    std::cout << std::hex;
    for(auto e : machine_code) {
        std::cout << (int)e << " ";
        konto++;
        if(konto % 7 == 0) {
            std::cout << '\n';
        }
    }
    std::cout << std::dec;
    std::cout << "\n\n";
}

int main() {
  float a,b = 0;
  std::cin >> a;
  std::cin >> b;

  std::cout << " sum of " << a << " " << b;

  const auto machine_code = sumCode();

  show_machine_code(machine_code);

  std::size_t required_memory_size = estimate_memory_size(machine_code.size());

  std::cout << " estimated memory size: " << required_memory_size << std::endl;

  uint8_t *mem = (uint8_t*) mmap(NULL, required_memory_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS ,-1, 0);

  if(mem == MAP_FAILED) {
    std::cerr << "Can't allocate memory\n"; std::exit(1);
  }

  for(size_t i = 0; i < machine_code.size(); ++i) {
    mem[i] = machine_code[i];
  }

  std::cout << " put in memory " << std::endl;

  float (*func)(float, float);

  func = (float (*)(float, float)) mem;

  func(a, b);

  std::cout << "sum is " << func(a,b) << std::endl;

  munmap(mem, required_memory_size);
}
