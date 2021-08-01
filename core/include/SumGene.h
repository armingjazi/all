#pragma once

#include "IGene.h"
namespace all {
class SumGene : public IGene {
public:
  std::vector<uint8_t> code() const override;
};
} // namespace all