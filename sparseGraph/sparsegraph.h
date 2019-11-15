#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <map>
#include <set>
using namespace std;

class SparseGraph{
protected:
    // Your code here
    size_t n;
    std::map<int, std::set<int>> edge;
public:
    SparseGraph() {
        // Your code here
        SparseGraph(3);
    }

    SparseGraph(int n_in) {
        // Your code here
        this->n = n_in;
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        this->n = G.n;
        this->edge = G.edge;
    }

    void AddEdge(int a, int b) {
        // Your code here
        edge[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        edge[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if (edge.count(a) != 0)
            return edge.at(a).count(b) != 0 ? true : false;
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph result(n);
        for (auto p : edge) {
        for (auto v : p.second) {
          result.AddEdge(v, p.first);
        }}
        return result;
    }

};
#endif // __SPARSE_GRAPH_H__

