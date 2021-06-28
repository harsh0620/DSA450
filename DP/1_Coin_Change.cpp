#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

class Solution
{
public:
    long long int count(int wt[], int n, int W)
    {
        long long int dp[n + 1][W + 1];
        for (int i = 0; i <= W; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - wt[i - 1]] + dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[m];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.count(a, m, n) << endl;
    }
    return 0;
}