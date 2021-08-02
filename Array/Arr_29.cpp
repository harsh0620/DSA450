#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int findMinDiff(vector<int> v, int n, int m)
    {
        //code
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        for (int i = 0; i + m - 1 < n; i++)
        {
            ans = min(v[i + m - 1] - v[i], ans);
        }
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.findMinDiff(a, n, m);
        cout << endl;
    }
    return 0;
}
