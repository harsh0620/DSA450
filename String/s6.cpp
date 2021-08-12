#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    bool check(string a, string b, string r)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(r.begin(), r.end());

        int i = 0, j = 0, k = 0;

        while (k != r.length())
        {
            if (i < a.length() && a[i] == r[k])
            {
                i++;
            }
            else if (j < b.length() && b[j] == r[k])
            {
                j++;
            }
            else
            {
                return false;
            }
            k++;
        }
        if (i < a.length() || j < b.length())
        {
            return true;
        }
        return false;
    }
    bool shuffleCheck(string a, string b, string r)
    {

        if ((a.length() + b.length()) == r.length() && check(a, b, r) == true)
        {

            return true;
        }
        else
        {

            return false;
        }
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
        string r;
        cin >> r;
        Solution ob;
        cout << ob.shuffleCheck(s, ss, r);

        cout << endl;
    }
    return 0;
}