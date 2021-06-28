#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

class Solution
{
public:
    bool knapsack(int W, int a[], int n)
    {
        int dp[n + 1][W + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = false;
                }
                if (j == 0)
                {
                    dp[i][j] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (a[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - a[i - 1]]);
                }
            }
        }
        return dp[n][W];
    }
    int equalPartition(int N, int a[])
    {
        int W = 0;

        for (int i = 0; i < N; i++)
        {
            W += a[i];
        }
        if (W % 2 != 0)
        {
            return 0;
        }
        else
        {
            W = W / 2;
            return knapsack(W, a, N);
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        if (ob.equalPartition(n, a))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}