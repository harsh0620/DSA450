#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int s, int V, vector<int> adj[], vector<bool> &vis)
{
    queue<pair<int, int>> q;
    q.push({s, -1});
    vis[s] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;

        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
                vis[it] = true;
            }
            else if (it != parent)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, V, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
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

    return 0;
}