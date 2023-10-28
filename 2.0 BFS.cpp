#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 100;
bool visited[M];
int dist[M];
vector<int> adj_list[M];

void bfs(int source, int n)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    dist[source] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj_list[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int source = 0;
    cout << "Enter Source:\n";
    cin >> source;
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        dist[i] = -1; // -1 represents infinity or unreachable
    }
    bfs(source, n);

    for (int i = 0; i < n; ++i)
    {
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}