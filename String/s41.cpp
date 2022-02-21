#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int transform(string A, string B)
    {
        // code here.
        int n = A.size();
        int m = B.size();
        if (n != m)
        {
            return -1;
        }
        int f[256] = {0};

        for (int i = 0; i < n; i++)
        {
            f[A[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            f[B[i]]--;
        }
        for (int i = 0; i < 256; i++)
        {
            if (f[i])
            {
                return -1;
            }
        }
        int ans = 0;
        for (int i = n - 1, j = m - 1; i >= 0;)
        {
            while (i >= 0 && A[i] != B[j])
            {
                i--;
                ans++;
            }
            if (i >= 0)
            {
                i--;
                j--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.transform(A, B) << endl;
    }
} // } Driver Code Ends