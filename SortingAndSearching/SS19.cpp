#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void hash0111()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    int Q[q];
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i];
    }
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int sum = 0, cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] <= Q[i])
            {
                sum += a[j];
                cnt++;
            }
        }
        cout << cnt << " " << sum << endl;
    }
}

int main()
{
    hash0111();
    // ll t;
    // cin >> t;
    // for (ll i = 1; i <= t; i++)
    // {
    solve();
    //}

    return 0;
}