#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    string findS(string s)
    {
        unordered_map<char, int> mp;
        string res = "";
        for (int i = 0; i < s.length() + 1; i++)
        {
            if (mp.find(s[i]) == mp.end() && i > 0)
            {
                auto it = mp.find(s[i - 1]);
                res += to_string(it->second) + it->first;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return res;
    }
    string countAndSay(int n)
    {

        string ans = "1";

        for (int i = 1; i < n; i++)
        {
            ans = findS(ans);
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
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countAndSay(n);

        cout << endl;
    }
    return 0;
}