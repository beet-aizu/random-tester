#include <cstddef>

template< typename CostType >
struct Edge {
  std::size_t u, v;
  CostType c;
  
  Edge(std::size_t u_, std::size_t v_, CostType c_) : u(u_), v(v_), c(c_) {}
};

