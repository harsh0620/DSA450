#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int dp[100][100];
class Solution
{
public:
    int mcm(int a[], int i, int j)
    {
        if (i == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            dp[i][j] = min(dp[i][j], mcm(a, i, k) + mcm(a, k + 1, j) + a[i - 1] * a[k] * a[j]);
        }
        return dp[i][j];
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
        memset(dp, -1, sizeof(dp));

        Solution ob;
        cout << ob.mcm(a, 1, n - 1);
    }
    return 0;
}