#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int maxSubstr(string s)
    {
        int n = s.length();
        int ans = 0;

        int cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                cnt0++;
            }
            else
            {
                cnt1++;
            }
            if (cnt1 == cnt0)
            {
                ans++;
            }
        }
        if (ans == 0)
        {
            return -1;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.maxSubstr(s);
    }
    return 0;
}