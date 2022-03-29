#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    void topoLogicalDFS(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                topoLogicalDFS(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    void revDFS(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        // cout << node << " ";
        for (auto x : adj[node])
        {
            if (vis[x])
            {
                ;
            }
            else
            {
                revDFS(x, adj, vis);
            }
        }
    }
    int kosaraju(int n, vector<int> adj[])
    {
        // code here
        stack<int> st;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                topoLogicalDFS(i, adj, vis, st);
            }
        }
        // step2:Take Transpose of graph
        vector<int> transpose[n];
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }
        // step3: Take DFS of transpose;
        int ans = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                // cout << "SCC: ";
                revDFS(node, transpose, vis);
                ans++;
                // cout << endl;
            }
        }
        return ans;
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
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends