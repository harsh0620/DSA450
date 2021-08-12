#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    string longestPalin1(string s)
    {
        string ans;
        int n = s.length();
        string prev;
        prev.push_back(s[0]);
        ans = prev;
        for (int i = 1; i < n; i++)
        {
            prev = s[i];
            for (int j = i - 1; j >= 0; j--)
            {
                string x = prev + s[j];
                string y = x;
                reverse(y.begin(), y.end());
                if (x == y)
                {
                    if (ans.length() < x.length())
                    {
                        ans = x;
                    }
                }
                prev = x;
            }
        }
        return ans;
    }
    string longestPalin2(string str)
    {
        int n = str.size();

        bool table[n][n];

        memset(table, 0, sizeof(table));

        int maxLength = 1;

        for (int i = 0; i < n; ++i)
            table[i][i] = true;

        int start = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (str[i] == str[i + 1])
            {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int k = 3; k <= n; ++k)
        {

            for (int i = 0; i < n - k + 1; ++i)
            {

                int j = i + k - 1;

                if (table[i + 1][j - 1] && str[i] == str[j])
                {
                    table[i][j] = true;

                    if (k > maxLength)
                    {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        string ans;
        for (int i = start; i <= start + maxLength - 1; ++i)
            ans.push_back(str[i]);

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
        cout << ob.longestPalin2(s);

        cout << endl;
    }
    return 0;
}