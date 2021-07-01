#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int lcs(int a, int b, string x, string y)
    {
        // your code here
        int m = x.length(), n = y.length();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
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
        string a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.lcs(n, m, a, b) << endl;
    }
    return 0;
}