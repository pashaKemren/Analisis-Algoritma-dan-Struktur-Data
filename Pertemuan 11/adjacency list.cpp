#include <iostream>
#include <vector>

class Graph {
    int V;
    bool is_directed;
    std::vector<std::vector<int> > adj;

public:
    Graph(int vertices, bool is__directed = false) {
        V = vertices;
        is_directed = is__directed;
        adj.resize(V);
    }

    // Add an edge to an undirected graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!is_directed) {
        	adj[v].push_back(u);
    }
}

void printGraph() {
    for (int i = 0; i < V; ++i) {
        std::cout << "Vertex " << i << ":";
        for (int j = 0; j < adj[i].size(); j++) {
            std::cout << " -> " << adj[i][j];
        }
        std::cout << "\n";
    }
}
};

int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph g(5, true);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the final representation
    g.printGraph();

    return 0;
}
