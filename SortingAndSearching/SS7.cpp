#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(int a[], int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (a[abs(a[i]) - 1] > 0)
            {
                a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
            }
            else
            {
                ans.push_back(abs(a[i]));
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                ans.push_back(i + 1);
                return ans;
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends