#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int dp[200][200][200];
class Solution
{
public:
    int lcs(int n, int m, int o, string &x, string &y, string &z)
    {
        // your code here

        if (n == 0 || m == 0 || o == 0)
        {
            return 0;
        }
        if (dp[n][m][o] != -1)
        {
            return dp[n][m][o];
        }
        if (x[n - 1] == y[m - 1] && y[m - 1] == z[o - 1])
        {
            return dp[n][m][o] = 1 + lcs(n - 1, m - 1, o - 1, x, y, z);
        }
        int p = lcs(n - 1, m, o, x, y, z);
        int q = lcs(n, m - 1, o, x, y, z);
        int r = lcs(n, m, o - 1, x, y, z);
        return dp[n][m][o] = max({p, q, r});
    }
};
int main()
{
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, o;
        cin >> n >> m >> o;
        string a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        cout << ob.lcs(n, m, o, a, b, c) << endl;
    }
    return 0;
}