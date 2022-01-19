#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &a)
    {
        int n = a.size();
        int idx = -1;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] > a[i - 1])
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            sort(a.begin(), a.end());
        }
        else
        {
            int prev = idx;
            for (int i = idx + 1; i < n; i++)
            {
                if (a[i] > a[idx - 1] && a[i] <= a[prev])
                {
                    prev = i;
                }
            }
            swap(a[idx - 1], a[prev]);
            sort(a.begin() + idx, a.end());
        }
    }
};
int main()
{
    return 0;
}