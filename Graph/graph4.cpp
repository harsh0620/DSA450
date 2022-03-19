#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isCyclic1(int n, vector<int> adj[])
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
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt == n)
        {
            return false;
        }
        return true;
    }
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
    bool isCyclic(int N, vector<int> adj[])
    {
        // code here
        int vis[N], dfsVis[N];
        memset(vis, 0, sizeof vis);
        memset(dfsVis, 0, sizeof dfsVis);
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                if (checkDirectedCycle(i, adj, vis, dfsVis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends