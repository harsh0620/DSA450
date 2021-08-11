#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    bool areRotations1(string a, string b)
    {

        if (a.length() != b.length())
        {
            return false;
        }
        string t = a + a;
        return (t.find(b) != string::npos);
    }
    bool areRotations2(string a, string b)
    {
        queue<char> sa, sb;
        if (a.length() != b.length())
        {
            return false;
        }
        for (int i = 0; i < a.size(); i++)
        {
            sa.push(a[i]);
        }
        for (int i = 0; i < b.size(); i++)
        {
            sb.push(b[i]);
        }
        int k = b.size();
        while (k--)
        {
            char x = sa.front();
            sa.pop();
            sa.push(x);
            if (sa == sb)
            {
                return true;
            }
        }
        return false;
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
        string ss;
        cin >> ss;
        Solution ob;
        cout << ob.areRotations2(s, ss);

        cout << endl;
    }
    return 0;
}
