#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_VERTICES = 100;
vector<int> adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];

void dfs(int source)
{
    stack<int> stk;
    stk.push(source);

    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();
        if (!visited[curr])
        {
            visited[curr] = true;
            cout << "Visited vertex: " << curr << endl;
            for (int go : adjList[curr])
            {
                if (!visited[go])
                    stk.push(go);
            }
        }
    }
}

int main()
{
    // Get the number of vertices and edges
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}