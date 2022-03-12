#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    cout << node << " ";
    for (auto x : adj[node])
    {
        if (vis[x])
        {
            ;
        }
        else
        {
            dfs(x, adj, vis);
        }
    }
}
void DFS(vector<int> adj[], int n)
{

    vector<bool> vis(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {

            dfs(i, adj, vis);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(adj, V);

    return 0;
}