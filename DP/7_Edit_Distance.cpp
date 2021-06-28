#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Code here
        int n = s.length();
        int m = t.length();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        cout << ob.editDistance(s, t) << endl;
    }
    return 0;
}