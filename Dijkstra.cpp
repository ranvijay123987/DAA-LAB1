#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    int graph[100][100] = {0};

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    int dist[100];
    bool visited[100];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex " << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << " : INF\n";
        else
            cout << "Vertex " << i << " : " << dist[i] << "\n";
    }

    cout << "\nTime Complexity: O(V^2)" << endl;
    cout << "Space Complexity: O(V^2)" << endl;

    return 0;
}