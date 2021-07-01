#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int dp[100][100];

class Solution
{
public:
    int PaintingTheFence(int n, int k)
    {

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = k;
        dp[2] = k * k;
        const int mod = 1e9 + 7;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
        }
        return dp[n];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.PaintingTheFence(n, k) << endl;
    }
    return 0;
}