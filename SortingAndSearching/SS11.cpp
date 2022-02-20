#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &a, int k)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int start = j + 1;
                int end = n - 1;
                int tsum = k - a[j] - a[i];

                while (start < end)
                {
                    int twosum = a[start] + a[end];
                    if (twosum < tsum)
                    {
                        start++;
                    }
                    else if (twosum > tsum)
                    {
                        end--;
                    }
                    else
                    {
                        vector<int> temp(4, 0);
                        temp[0] = a[i];
                        temp[1] = a[j];
                        temp[2] = a[start];
                        temp[3] = a[end];
                        sort(temp.begin(), temp.end());
                        ans.push_back(temp);

                        while (start < end && a[start] == temp[2])
                        {
                            start++;
                        }
                        while (start < end && a[end] == temp[3])
                        {
                            end--;
                        }
                    }
                }
                while (j + 1 < n && a[j] == a[j + 1])
                {
                    j++;
                }
            }
            while (i + 1 < n && a[i] == a[i + 1])
            {
                i++;
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends