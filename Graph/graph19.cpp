#include <bits/stdc++.h>
using namespace std;
int MSTPRIMSEFFICIENT(int V, vector<vector<int>> adj[])
{
    // code here
    int n = V;
    int parent[n];
    int keys[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
    {
        // parent[i]=-1;
        keys[i] = INT_MAX;
        mstSet[i] = false;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    keys[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    for (int i = 0; i < n - 1; i++)
    {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;
        for (auto it : adj[u])
        {
            int v = it[0];
            int weight = it[1];

            if (mstSet[v] == false && weight < keys[v])
            {
                parent[v] = u;
                keys[v] = weight;
                pq.push({keys[v], v});
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // cout<<keys[i]<<" ";
        sum += keys[i];
    }
    return sum;
}
int main()
{
    return 0;
}