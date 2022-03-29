#include <bits/stdc++.h>
using namespace std;
bool checkDirectedCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkDirectedCycle(it, adj, vis, dfsVis))
            {
                return true;
            }
        }
        else if (dfsVis[it] && vis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}
bool canFinish(vector<pair<int, int>> v, int n)
{
    vector<int> adj[n + 1];
    for (int i = 0; i < v.size(); i++)
    {
        adj[v[i].second].push_back(v[i].first);
    }
    int N = n;
    int vis[N], dfsVis[N];
    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i] && checkDirectedCycle(i, adj, vis, dfsVis))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << canFinish(v, n);
    return 0;
}