#include <random>
#include <vector>
#include <algorithm>
#include <numeric>

#include "random_number_generator.hpp"
class RandomPermutationGenerator {
  int n;

  std::random_device seed_gen;
  std::default_random_engine engine;

public:
  RandomPermutationGenerator(std::size_t sz) : n(sz), engine(seed_gen()) {}

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
