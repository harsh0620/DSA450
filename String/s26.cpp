// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int romanToDecimal(string &str)
    {
        // code here
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int prev = mp[str[str.length() - 1]];
        int ans = prev;
        for (int i = str.length() - 2; i >= 0; i--)
        {
            if (mp[str[i]] >= prev)
            {
                ans += mp[str[i]];
            }
            else
            {
                ans -= mp[str[i]];
            }
            prev = mp[str[i]];
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
} // } Driver Code Ends