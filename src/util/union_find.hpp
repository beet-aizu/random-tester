#include <algorithm>
#include <cstddef>
#include <vector>

class UnionFind {
  vector< int > rs, ps;
  std::size_t num;

public:
  UnionFind(std::size_t n) : num(n), rs(n, 1), ps(n) {
    iota(ps.begin(), ps.end(), 0);
  }

  int find(int x) {
    return (x == ps[x] ? x : ps[x] = find(ps[x]));
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rs[x] < rs[y]) std::swap(x, y);
    rs[x] += rs[y];
    ps[y] = x;
    num--;
  }

  int size(int x) {
    return rs[find(x)];
  }

  std::size_t count() const {
    return num;
  }
};
