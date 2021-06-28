#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

class Solution
{
public:
    const int mod = 1e9 + 7;
    int min(int a, int b)
    {
        return (a < b) ? a : b;
    }
    int nCr(int n, int r)
    {
        // code here

        if (r > n)
        {
            return 0;
        }

        int dp[n + 1][r + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= min(r, i); j++)
            {
                if (j == 0 || j == i)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
                }
            }
        }
        return dp[n][r];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}