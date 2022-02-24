#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int help)
    {
        // vector<int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     ans.push_back(arr1[i]);
        // }
        // for(int i=0;i<m;i++)
        // {
        //     ans.push_back(arr2[i]);
        // }
        // sort(ans.begin(),ans.end());

        // return ans[k-1];
        int i = 0, j = 0, k = n - 1;

        while (i <= k && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                i++;
            }
            else
            {
                swap(arr2[j++], arr1[k--]);
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
        if (help <= n)
        {
            return arr1[help - 1];
        }
        return arr2[help - n - 1];
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
} // } Driver Code Ends