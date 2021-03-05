#include <cassert>
#include <string>
#include "./random_number_generator.hpp"

class RandomCharacterGenerator {
  RandomNumberGenerator<int> rng;
  bool used[128] = {};
  std::string chars;

public:
  RandomCharacterGenerator() {}

  void use(char c) {
    assert(32 < c and c < 127);
    if (used[(int)c]) return;
    used[(int)c] = true;
    chars += c;
  }

  void use(std::string s) {
    for (const char &c: s) use(c);
  }

  void use_lower() {
    for (char c = 'a'; c <= 'z'; c++) {
      use(c);
    }
  }

  void use_upper() {
    for (char c = 'A'; c <= 'Z'; c++) {
      use(c);
    }
  }

  char operator() () {
    assert(chars.size() != 0);
    return chars[rng.range(0, chars.size() - 1)];
  }
};
