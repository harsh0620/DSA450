#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    kthSmallestElement1(int a[], int n, int k)
    {
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
        }
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            count += it->second;
            if (count >= k)
            {
                return it->first;
            }
        }
        return -1;
    }
    kthSmallestElement2(int a[], int n, int k)
    {
        sort(a, a + n);
        return a[k - 1];
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.kthSmallestElement1(a, n, k) << endl;
        cout << ob.kthSmallestElement1(a, n, k) << endl;
    }
    return 0;
}