
// 24BCS12643 
// UID: Himanshu Kumar

// Prims Algorithm:
// 	1.	Choose any vertex s as the starting vertex.
// 	2.	Mark all vertices as unvisited.
// 	3.	Use a min-priority queue to store (weight, vertex) pairs.
// 	4.	Insert (0, s) into the priority queue.
// 	5.	While the priority queue is not empty: 
// 		•	Extract the vertex with minimum weight.
//     •	Mark the vertex as visited.
// 		•	If the vertex is already visited, ignore it.
// 		•	Otherwise:
// 			•	Add the weight to the MST cost.
// 			•	Insert all edges from this vertex to unvisited vertices into the priority queue.
// 	6.	When all vertices are visited, the MST is complete.
// Time Complexity: (V+E)log(V)
// Worst Case Time Complexity: (E+E)logV = 2ElogV or  ElogV, because in a graph, no of edges could be more than vertices.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the edges (u v weight):" << endl;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << endl;
        }
    }
    return 0;
}