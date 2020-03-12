#include <vector>

class UnionFind {
 private:
    // positive: parent node id
    // negative: -groupsize (and itself is a root node)
    std::vector<int> data;
    int groups_;

 public:
    const int nodes; const int& groups;
    UnionFind(const int size) : data(size, -1), groups_(size), nodes(size), groups(groups_){}

    bool unite(const int x, const int y) {
        int rx = getRoot(x), ry = getRoot(y);
        if (rx == ry) return false;
        if (data[ry] < data[rx]) std::swap(rx, ry);
        data[rx] += data[ry];
        data[ry] = rx;
            --groups_;
        return true;
        }

    bool areSame(const int x, const int y) { return getRoot(x) == getRoot(y); }
    int getRoot(const int x) { return data[x] < 0 ? x : data[x] = getRoot(data[x]); }
    int getGroupSize(const int x) { return -data[getRoot(x)]; }
};
