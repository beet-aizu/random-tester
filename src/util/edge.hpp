#include <cstddef>

template< typename CostType >
class edge {
  std::size_t u, v;
  CostType c;
  
  edge(std::size_t u_, std::size_t v_, CostType c_) : u(u_), v(v_), c(c_) {}
};

