#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__
#include <set>
#include <map>

class DenseGraph{
public:
    DenseGraph(): DenseGraph(3) {}
    DenseGraph(int n_in): n(n_in) {}
    DenseGraph(const DenseGraph& G): n(G.n), edge(G.edge) {}

    void AddEdge(int a, int b) {
        edge[a].insert(b);
    }
    void RemoveEdge(int a, int b) {
        edge[a].erase(b);
    }
    bool DoesEdgeExist(int a, int b) const {
            return edge.count(a) ? edge.at(a).count(b) : false;
    }
    DenseGraph Transpose() const {
        DenseGraph result(n);
        for (auto p : edge) {
        for (auto v : p.second) {
          result.AddEdge(v, p.first);
        }}
        return result;
    }
protected:
    size_t n;
    std::map<int, std::set<int>> edge;
};
#endif // __DENSE_GRAPH_H__
