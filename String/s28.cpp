#include <bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << minFlips(s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

int minFlips(string S)
{
    // your code here
    int ans1 = 0, ans2 = 0;
    int n = S.length();
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            if (S[i] != '0')
            {
                ans1++;
            }
        }
        else
        {
            if (S[i] != '1')
            {
                ans1++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            if (S[i] != '1')
            {
                ans2++;
            }
        }
        else
        {
            if (S[i] != '0')
            {
                ans2++;
            }
        }
    }
    return min(ans1, ans2);
}