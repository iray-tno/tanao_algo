#include <vector>

class UnionFind {
 private:
    std::vector<int> p_gs_; //正なら親ノードの番号で負なら自身がルートで値は-groupsize
    int groups_;

 public:
    const int nodes;

    UnionFind(int size) : p_gs_(size, -1), nodes(size), groups_(size) {}

    bool unite(int x, int y) {
        int rx = root(x), ry = root(y); // XXX: 引数をそのまま使った方が高速だった（ときがあった）
        if (rx != ry) {
            --groups_;
            //rx<ryにしてrxにryを連結
            if(p_gs_[ry] < p_gs_[rx]) std::swap(rx, ry);
            p_gs_[rx] += p_gs_[ry];
            p_gs_[ry] = rx;
        }
        return rx != ry;
    }

    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return p_gs_[x] < 0 ? x : p_gs_[x] = root(p_gs_[x]); }
    int gsize(int x) { return -p_gs_[root(x)]; }
    int groups() const { return groups_; }
};
