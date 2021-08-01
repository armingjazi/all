#pragma once
#include "vector"

namespace all {
class IGene {
public:
  virtual ~IGene() = default;
  virtual std::vector<uint8_t> code() const = 0;
};

using GenePtr = std::unique_ptr<IGene>;
} // namespace all