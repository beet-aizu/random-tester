#include <random>
#include <vector>
#include <algorithm>
#include <numeric>

#include "random_number_generator.hpp"
template< int N_MIN, int N_MAX > 
class RandomPermutationGenerator {
  RandomNumberGenerator<int> rng;

  int n;

  std::random_device seed_gen;
  std::default_random_engine engine;

public:
  RandomPermutationGenerator() : n(rng.range(N_MIN, N_MAX)), engine(seed_gen()) {}

  std::size_t size() {
    return n;
  }

  std::vector< int > make_0indexed() {
    std::vector< int > ps(n);
    std::iota(ps.begin(), ps.end(), 0);
    std::shuffle(ps.begin(), ps.end(), engine);
    return ps;
  }

  std::vector< int > make_1indexed() {
    std::vector< int > ps(n);
    std::iota(ps.begin(), ps.end(), 1);
    std::shuffle(ps.begin(), ps.end(), engine);
    return ps;
  }
};
