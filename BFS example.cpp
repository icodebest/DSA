#include <iostream>
#include <queue>

using namespace std;

const int MAX_NODES = 100; // Assuming a maximum of 100 nodes

struct Edge {
    int src, dest;
    float weight;
};

struct Node {
    int id;  // Node ID
    float weight;
};

class Graph {
public:
    Node adjList[MAX_NODES][MAX_NODES]; // 2D array for adjacency list
    int nodes;

    Graph(int N) : nodes(N) {
        for (int i = 0; i < MAX_NODES; ++i)
            for (int j = 0; j < MAX_NODES; ++j)
                adjList[i][j] = {0, 0.0};
    }

    void addEdge(int src, int dest, float weight) {
        adjList[src][dest] = {dest, weight};
        adjList[dest][src] = {src, weight}; // For undirected graph
    }
};

void printGraph(Graph const &graph) {
    cout << "The graph is as follows:\n";
    for (int i = 0; i < graph.nodes; i++) {
        cout << i << " --> ";

        for (int j = 0; j < graph.nodes; j++)
            if (graph.adjList[i][j].id != 0)
                cout << "(" << graph.adjList[i][j].id << ", " << graph.adjList[i][j].weight << ") ";

        cout << endl;
    }
}

void BFS(Graph const &graph, int start) {
    vector<bool> discovered(graph.nodes, false);
    queue<int> q;

    discovered[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int u = 0; u < graph.nodes; u++)
            if (!discovered[u] && graph.adjList[v][u].id != 0) {
                discovered[u] = true;
                q.push(u);
            }
    }
}

int main() {
    Graph graph(7);

    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 3, 1.29);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 3.459);
    graph.addEdge(2, 4, 2);
    graph.addEdge(4, 5, 5.3);
    graph.addEdge(5, 6, 6.1);

    printGraph(graph);
    cout << "BFS starting from node " << 0 << ": ";
    BFS(graph, 0);

    return 0;
}

