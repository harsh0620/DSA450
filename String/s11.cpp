#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    vector<string> ans;
    void permute(string s, int l, int r)
    {
        if (l == r)
        {
            ans.push_back(s);
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(s[l], s[i]);

                permute(s, l + 1, r);

                swap(s[l], s[i]);
            }
        }
    }
    vector<string> find_permutation(string S)
    {
        // Code here there
        int n = S.length();
        permute(S, 0, n - 1);
        vector<string> res = ans;
        sort(res.begin(), res.end());
        return res;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> ans = ob.find_permutation(s);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}