#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int isIp(string s)
    {
        vector<string> v;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
            {
                v.push_back(temp);
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        v.push_back(temp);
        // cout << stoi(v[0]) * 100 << endl;
        for (int i = 0; i < v.size(); i++)
        {
            long long x = stoi(v[i]);
            if (v[i].size() > 3 || x < 0 || x > 255)
            {
                return 0;
            }
            if (v[i].size() > 1 && x == 0)
            {
                return 0;
            }
            if (v[i].size() > 1 && x != 0 && v[i][0] == '0')
            {
                return 0;
            }
        }
        return 1;
    }
    vector<string> findIp(string s)
    {
        int n = s.length();
        vector<string> ans;
        if (n > 12 || n < 4)
        {
            return ans;
        }

        string check = s;
        for (int i = 1; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    check = check.substr(0, k) + "." + check.substr(k);
                    check = check.substr(0, j) + "." + check.substr(j);
                    check = check.substr(0, i) + "." + check.substr(i);
                    // cout << check << " ";

                    if (isIp(check))
                    {
                        ans.push_back(check);
                        // cout << check << endl;
                    }
                    check = s;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution ob;

    string s;
    cin >> s;

    vector<string> ans = ob.findIp(s);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}