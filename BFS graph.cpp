#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    vector<vector<double> > adj; // Adjacency Lists

    // Function to add an edge to the graph
    void addEdge(double v, double w);

    // Prints BFS traversal from a given source s
    void BFS(double s);
};

void Graph::addEdge(double v, double w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(double s) {
    // Mark all the vertices as not visited
    vector<bool> visited(adj.size(), false);

    // Create a queue for BFS
    queue<double> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        s = q.front();
        cout << s << " ";

        q.pop();

        /* Get all adjacent vertices of the dequeued vertex s.
           If an adjacent has not been visited, then mark it visited and enqueue it */

        for (double i ::adj[s]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cout << "Create the following graph:\n"
         << "1.29 - 3.459 - 3.2 - 5.3 \n"
         << "|         |     |\n"
         << "1.2 ----- 6.1 --|\n";

    Graph g(7); // Assuming there are 7 vertices in the graph

    g.addEdge(0, 1);
    g.addEdge(0, 5);

    g.addEdge(1, 2);

    g.addEdge(2, 3);
    g.addEdge(2, 6);

    g.addEdge(3, 4);

    cout << "Following is Breadth First Traversal (starting from vertex 3): ";
    g.BFS(3);
    cout << endl;

    return 0;
}

