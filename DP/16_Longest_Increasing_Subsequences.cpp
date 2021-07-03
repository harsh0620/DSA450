#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int ceilIdx(vector<int> tail, int l, int r, int x)
    {
        while (r > l)
        {
            int m = l + (r - l) / 2;
            if (tail[m] >= x)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return r;
    }
    int longestSubsequence(int n, int a[])
    {
        vector<int> tail;
        int len = 1;
        tail.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > tail[len - 1])
            {
                tail.push_back(a[i]);
                len++;
            }
            else
            {
                int c = ceilIdx(tail, 0, len - 1, a[i]);
                tail[c] = a[i];
            }
        }
        return len;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
    }
    return 0;
}