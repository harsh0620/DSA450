#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u, v, wt;
    node(int f, int s, int wait)
    {
        u = f;
        v = s;
        wt = wait;
    }
};
int findParent(int node, int parent[])
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}
void unionn(int u, int v, int parent[], int rank[])
{
    u = findParent(u);
    v = findParent(v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        rank[u]++;
        parent[v] = u;
    }
}
bool comp(node a, node b)
{
    return a.wt < b.wt;
}
int kruskalsMST(vector<node> v)
{
    int cost = 0;
    vector<int> parent(n, 0), rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<pair<int, int>> mst;
    sort(v.begin(), v.end(), comp);
    for (auto it : v)
    {
        if (findParent(it.u, parent) != findParent(it.v, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(u, v, parent, rank);
        }
    }
    return cost;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<struct node> v;
    for (int i = 0; i < n; i++)
    {
        struct node dat;

        cin >> dat.u >> dat.v >> dat.wt;
        v.push_back(dat);
    }
    cout << kruskalsMST(v) << endl;
    return 0;
}