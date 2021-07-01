#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int dp[100][100];

class Solution
{
public:
    int maximizeTheCuts(int n, int p, int q, int r)
    {
        //Your code here
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));

        dp[0] = 0;

        for (int i = 0; i <= n; i++)
        {
            if (dp[i] == -1)
                continue;

            // if a segment of p is possible
            if (i + p <= n)
                dp[i + p] = max(dp[i + p], dp[i] + 1);

            // if a segment of q is possible
            if (i + q <= n)
                dp[i + q] = max(dp[i + q], dp[i] + 1);

            // if a segment of r is possible
            if (i + r <= n)
                dp[i + r] = max(dp[i + r], dp[i] + 1);
        }
        if (dp[n] == -1)
        {
            dp[n] = 0;
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
        int n;
        cin >> n;
        int p, q, r;
        cin >> p >> q >> r;

        Solution ob;
        cout << ob.maximizeTheCuts(n, p, q, r) << endl;
    }
    return 0;
}