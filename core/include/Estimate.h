#pragma once

#include <unistd.h>

namespace all {
std::size_t estimate_memory_size(size_t machine_code_size) {
  size_t page_size_multiple = sysconf(_SC_PAGE_SIZE);
  size_t factor = 1, required_memory_size;

  for (;;) {
    required_memory_size = factor * page_size_multiple;
    if (machine_code_size <= required_memory_size)
      break;
    factor++;
  }
  return std::size_t(required_memory_size);
}
} // namespace all