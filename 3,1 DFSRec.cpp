#include <iostream>
#include <vector>
using namespace std;

const int MAX_VERTICES = 100; // Adjust the maximum number of vertices as needed

vector<int> adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];

void dfs(int u)
{
    visited[u] = true;
    cout << "Visited vertex: " << u << endl;

    for (int v : adjList[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int n, m; // n is the number of vertices, m is the number of edges
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // adjList[v].push_back(u); // For an undirected graph
    }

    // Initialize the visited array
    for (int i = 0; i < n; ++i)
        visited[i] = false;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }

    return 0;
}
