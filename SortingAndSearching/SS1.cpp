#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int first = 0, last = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == x)
            {
                last = i;
                break;
            }
        }
        if (first == 0 || last == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << first << " " << last << endl;
        }
    }
    return 0;
}