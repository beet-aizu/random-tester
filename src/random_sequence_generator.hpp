#include <vector>
#include <cstddef>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <cassert>

#include "random_number_generator.hpp"

template< typename T, T MIN, T MAX, bool UNIQUE_VAL>
std::vector< T > random_sequence_generator(std::size_t n) {
  RandomNumberGenerator< T > rng;
  std::vector< T > as(n);

  if (UNIQUE_VAL) {
    const T LEN = MAX - MIN + 1;
    assert(LEN >= n);

    if (LEN <= 2 * n) {
      std::random_device seed_gen;
      std::default_random_engine engine(seed_gen());
      std::vector< T > bs(MAX - MIN + 1);
      std::iota(bs.begin(), bs.end(), MIN);
      std::shuffle(bs.begin(), bs.end(), engine);
      for (std::size_t i = 0; i < n; i++) {
        as[i] = bs[i];
      }
    } else {
      std::unordered_set< T > st;
      for (auto &a : as) {
        do {
          a = rng(MIN, MAX);
        } while (st.count(a));
        st.insert(a);
      }
    }
  } else {
    for (auto &a : as) a = rng(MIN, MAX);
  }
  return as;
}
