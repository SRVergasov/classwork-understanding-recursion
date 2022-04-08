#pragma once

#include <cstdint>  // uint64_t
#include <vector>

namespace assignment {

  // Используя две вспомогательные переменные (сложность по памяти ~ O(1)).
  uint64_t fib_iterative(int n);

  // Сложность по времени и памяти?
  uint64_t fib_recursive(int n);

  uint64_t fib_recursive_memoization(int n, std::vector<uint64_t>& cache);

  // Ref: https://en.wikipedia.org/wiki/Jacques_Philippe_Marie_Binet
  uint64_t fib_binet(int n);

}  // namespace assignment