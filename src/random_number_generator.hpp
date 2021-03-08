#include <random>

template < typename T >
class RandomNumberGenerator {
  std::random_device seed_gen;
  std::default_random_engine engine;

public:
  RandomNumberGenerator() : engine(seed_gen()) {}

  T operator() (T l, T r) {
    std::uniform_int_distribution<T> rng(l, r);
    return rng(engine);
  }
    
  T range(T l, T r) {
    std::uniform_int_distribution<T> rng(l, r);
    return rng(engine);
  }
};
