#include <iostream>
#include <queue>
#include <map>

#define INF 99999

using namespace std;

class Graph {
    int V; // Number of vertices
    map<string, map<string, int> > adjMatrix; // Adjacency matrix: weights

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(string u, string v, int w) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w; // Assuming the graph is undirected
    }

    void dijkstra(string src) {
        priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
        map<string, int> dist;

        for (auto const& pair : adjMatrix) {
            dist[pair.first] = INF;
        }

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            string u = pq.top().second;
            pq.pop();

            for (auto const& pair : adjMatrix[u]) {
                string v = pair.first;
                int weight = pair.second;

                if (weight > 0 && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances
        cout << "Vertex \t Distance from Source\n";
        for (auto const& pair : dist)
            cout << pair.first << "\t\t" << pair.second << "\n";
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

//    cout << "Enter edges (source, destination, weight):" << endl;
//    for (int i = 0; i < E; ++i) {
//        string u, v;
//        int w;
//        cout << "Edge " << i + 1 << "\nSource: ";
//        cin >> u ;
//		cout<<"Destination: ";
//		cin >> v ;
//		cout<<"Weight: ";
//		cin >> w;
//        g.addEdge(u, v, w);
//    }

	g.addEdge("Nashville","Atlanta",2);
	g.addEdge("Nashville","Memphis",15);
	g.addEdge("Atlanta","Savannah",1);
	g.addEdge("Atlanta","Memphis",10);
	g.addEdge("Savannah","Mobile",6);
	g.addEdge("Memphis","Mobile",7);
	g.addEdge("Mobile","New Orleans",3);
	g.addEdge("Memphis","New Orleans",3);
	

    string src;
    cout << "Enter source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}

