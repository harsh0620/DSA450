#include <bits/stdc++.h>
#define ll long long int
#define vvi vector<vector<ll>>
using namespace std;
const ll MOD = 1000000007;

void solve()
{
    string s, ans;
    cin >> s;
    int n = s.length();
    int k = n;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    int maxi = INT_MIN;
    for (auto it : mp)
    {
        maxi = max(maxi, it.second);
    }
    if (maxi <= n - maxi + 1)
    {
        cout << 1 << endl;
        return;
    }
    cout << 0 << endl;
    return;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}