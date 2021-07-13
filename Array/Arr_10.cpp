#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int minJumps(int a[], int n)
    {
        int dp[n];
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++)
            {
                if (a[j] + j >= i)
                {
                    if (dp[j] != INT_MAX)
                    {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return (dp[n - 1] == INT_MAX ? -1 : dp[n - 1]);
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
        cout << ob.minJumps(a, n) << " ";
    }
    return 0;
}