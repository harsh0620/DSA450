#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> topoSortBFS(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }
    // /vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // cout << node << endl;
        // ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                ans[it] = ans[node] + 1;
                q.push(it);
            }
        }
    }
    return ans;
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
        // adj[v].push_back(u);
    }
    vector<int> ans;
    ans = topoSortBFS(V, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}