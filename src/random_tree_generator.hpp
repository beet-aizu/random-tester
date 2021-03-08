#include <vector>
#include <cstddef>

#include "util/edge.hpp"
#include "random_number_generator.hpp"

template< typename CostType, CostType MIN, CostType MAX>
class RandomTreeGenerator {
  RandomNumberGenerator< int > rng;
  using edge = Edge<CostType>;

  std::size_t n;
  std::vector< std::size_t > ps;

public:
  RandomTreeGenerator(std::size_t sz) : n(sz), ps(n, -1) {
    for (int v = 1; v < (int)n; v++) {
      ps[v] = rng(0, v - 1);
    }
  }

  std::vector< edge > get_edges() {
    std::vector< edge > edges;
    for (std::size_t v = 1; v < n; v++) {
      edges.emplace_back(ps[v], v, rng(MIN, MAX));
    }
    return edges;
  }
};
