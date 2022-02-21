#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int answer(int a[], int n, int x, int k)
    {
        int i = 0;
        while (i < n)
        {
            if (a[i] == x)
            {
                return i;
            }
            // cout << a[i] << " ";
            i = i + max(1, (abs(a[i] - x) / k));
        }
        return -1;
    }
};
int main()
{
    Solution ob;

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x, k;
    cin >> x >> k;
    // cout << x << " " << k << endl;
    cout << ob.answer(a, n, x, k);

    return 0;
}