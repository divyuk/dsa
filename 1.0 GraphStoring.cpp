// Graph is stored in adjancey list or adjancy matrix

#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3 + 10; // Define the maximum number of vertices globally

// This is the adjacency list
vector<int> list[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // This is the adjacency matrix.
    int n, m;
    cin >> n >> m;

    // Initialize the adjacency matrix
    vector<vector<int>> mat(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;

        // Update the adjacency matrix
        mat[u][v] = 1;
        mat[v][u] = 1;

        // Update the adjacency list
        list[u].push_back(v);
        list[v].push_back(u);
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "Vertex " << i << ": ";
        for (int neighbor : list[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
