#include <iostream>
#include <chrono>

#include "assignment/linked_list.hpp"
#include "assignment/fibonacci.hpp"

using namespace std;
using namespace assignment;

using TimeItDuration = chrono::nanoseconds;

// вспомогательная функция для замера времени работы алгоритма F
template<typename F, typename... Args, typename Clock = chrono::high_resolution_clock,
         typename Duration = TimeItDuration>
auto timeit(F fun, Args&&... args) {
  const auto start_time = Clock::now();
  auto ret = fun(std::forward<Args>(args)...);
  const auto end_time = Clock::now();
  return std::make_pair(ret, chrono::duration_cast<Duration>(end_time - start_time).count());
}

int main() {

  // 1. Перевернуть связный список: итеративный и рекурсивный алгоритмы
  auto list = LinkedList({0, 1, 2, 3, 4});

  cout << "Original: " << list << '\n';

  list.ReverseRecursive();

  cout << "Reversed: " << list << '\n';

  // 2. Вычисление числа Фибоначчи

  constexpr int N = 42;

  // кеш (почему размер N + 1?)
  std::vector<uint64_t> cache(N + 1, 0);
  cache[0] = 0;
  cache[1] = 1;

  // замер времени работы

  const auto iter_result = timeit(fib_iterative, N);
  printf("Iterative: Fib(%d) = %llu ~ in %llu\n", N, iter_result.first, iter_result.second);

  const auto rec_result = timeit(fib_recursive, N);
  printf("Recursive: Fib(%d) = %llu ~ in %llu\n", N, rec_result.first, rec_result.second);

  const auto mem_result = timeit(fib_recursive_memoization, N, cache);
  printf("Recursive /w memoization: Fib(%d) = %llu ~ in %llu\n", N, mem_result.first, mem_result.second);

  const auto binet_result = timeit(fib_binet, N);
  printf("Binet: Fib(%d) = %llu ~ in %llu\n", N, binet_result.first, binet_result.second);


  // timer duration
  if constexpr (std::is_same_v<TimeItDuration, chrono::nanoseconds>) {
    cout << "Time measurements are in nanoseconds.\n";
  } else if constexpr (std::is_same_v<TimeItDuration, chrono::milliseconds>) {
    cout << "Time measurements are in milliseconds.\n";
  }

  return 0;
}
