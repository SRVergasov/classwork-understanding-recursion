#include "assignment/fibonacci.hpp"

#include <cassert>  // assert
#include <cmath>    // sqrt, pow

namespace assignment {

  uint64_t fib_iterative(int n) {
    assert(n >= 0);

    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; ++i) {
      int next = a + b;
      a = b;
      b = next;
    }
    return b;

    return 0;
  }

  uint64_t fib_recursive(int n) {
    assert(n >= 0);

    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  uint64_t fib_recursive_memoization(int n, std::vector<uint64_t>& cache) {
    assert(n >= 0);

    cache[0] = 0;
    cache[1] = 1;

    for (int i = 2; i <= n; ++i) {
      cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
  }

  uint64_t fib_binet(int n) {
    assert(n >= 0);

    int u = (int) ((pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n))/(pow(2, n) * sqrt(5)));

    return u + 1;
  }

}  // namespace assignment
