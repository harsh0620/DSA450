#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    void badCharHeuristic(string pat, int m, int badHeuristic[])
    {
        int i;
        for (i = 0; i < 256; i++)
            badHeuristic[i] = -1;
        for (i = 0; i < m; i++)
            badHeuristic[(int)pat[i]] = i;
    }
    void boyerMoore(string txt, string pat)
    {
        int n = txt.length();
        int m = pat.length();
        int badHeuristic[256];

        badCharHeuristic(pat, m, badHeuristic);

        int s = 0;
        while (s <= (n - m))
        {
            int j = m - 1;

            while (j >= 0 && pat[j] == txt[s + j])
                j--;

            if (j < 0)
            {
                cout << "pattern occurs at shift = " << s << endl;
                s += (s + m < n) ? m - badHeuristic[txt[s + m]] : 1;
            }
            else
                s += max(1, j - badHeuristic[txt[s + j]]);
        }
    }
};
int main()
{
    Solution ob;

    string txt, pat;
    cin >> txt >> pat;
    ob.boyerMoore(txt, pat);
    return 0;
}