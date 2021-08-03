#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int PalinArray(int a[], int n)
    { //add code here.
        int cnt = 0;
        int x = 0, r = 0;

        for (int i = 0; i < n; i++)
        {
            string s, b;
            x = a[i];
            b = to_string(x);
            while (x != 0)
            {
                r = x % 10;
                x = x / 10;
                s += to_string(r);
            }

            if (b == s)
            {
                cnt++;
            }
        }

        if (cnt == n)
        {
            return 1;
        }
        return 0;
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
        cout << ob.PalinArray(a, n);
        cout << endl;
    }
    return 0;
}
