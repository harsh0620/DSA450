#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int a[], int n)
    {
        ll dp[n] = {0};
        dp[0] = a[0];
        int x = 0;

        for (ll i = 1; i < n; i++)
        {

            int y = dp[i - 1];
            dp[i] = max(a[i] + x, y);
            x = dp[i - 1];
        }

        return dp[n - 1];
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends