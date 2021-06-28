#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

class Solution
{
public:
    int permuteCoefficient(int n, int k)
    {
        int fact[n + 1];
        fact[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            fact[i] = i * fact[i - 1];
        }
        return fact[n] / fact[n - k];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        Solution ob;
        cout << ob.permuteCoefficient(n, k) << endl;
    }
    return 0;
}