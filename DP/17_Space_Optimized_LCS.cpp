#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int lcs(string &x, string &y)
    {
        // your code here
        int m = x.length(), n = y.length();
        int dp[2][n + 1];
        bool bi;

        for (int i = 0; i <= m; i++)
        {
            bi = (i & 1);
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[bi][j] = 0;
                }
                else if (x[i - 1] == y[j - 1])
                {
                    dp[bi][j] = 1 + dp[1 - bi][j - 1];
                }
                else
                {
                    dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
                }
            }
        }
        return dp[bi][n];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.lcs(a, b) << endl;
    }
    return 0;
}