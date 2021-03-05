#include <random>

template < typename T >
class RandomNumberGenerator {
  std::random_device seed_gen;
  std::default_random_engine engine;

public:
  RandomNumberGenerator() : engine(seed_gen()) {}

  T range(T l, T r) {
    std::uniform_int_distribution<> rng(l, r);
    return rng(engine);
  }
};
