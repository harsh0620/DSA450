#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    vector<int> computeLPSArray(string str)
    {
        int M = str.length();
        vector<int> lps(M);

        int len = 0;
        lps[0] = 0; // lps[0] is always 0

        // the loop calculates lps[i] for i = 1 to M-1
        int i = 1;
        while (i < M)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else // (str[i] != str[len])
            {
                // This is tricky. Consider the example.
                // AAACAAAA and i = 7. The idea is similar
                // to search step.
                if (len != 0)
                {
                    len = lps[len - 1];

                    // Also, note that we do not increment
                    // i here
                }
                else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool isPalindrome(string s)
    {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minAddition(string s)
    {
        int cnt = 0;
        int n = s.length();
        bool flag = false;
        while (s.length() > 0)
        {
            if (isPalindrome(s))
            {
                flag = true;
                break;
            }
            else
            {
                cnt++;
                s.erase(s.begin() + s.length() - 1);
            }
        }
        if (flag == true)
        {
            return cnt;
        }
        return -1;
    }
    int minAddition2(string s)
    {
        string ss = s;

        reverse(ss.begin(), ss.end());
        string str = s + "#" + ss;
        vector<int> lps = computeLPSArray(str);
        return s.length() - lps.back();
    }
};
int main()
{
    Solution ob;

    string s;
    cin >> s;

    int ans = ob.minAddition(s);
    int ans2 = ob.minAddition2(s);

    cout << ans << endl
         << ans2 << endl;

    return 0;
}