#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void unionOfArray(int a[], int n, int b[], int m)
    {
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                cout << a[i++] << " ";
            }
            else if (a[i] > b[j])
            {
                cout << b[j++] << " ";
            }
            else
            {
                cout << a[i] << " ";
                i++;
                j++;
            }
        }
        while (i < n)
        {
            cout << a[i] << " ";
            i++;
        }
        while (j < m)
        {
            cout << b[j] << " ";
            j++;
        }
    }
    void intersectionArray(int a[], int n, int b[], int m)
    {
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                i++;
            }
            else if (a[i] > b[j])
            {
                j++;
            }
            else
            {
                cout << a[i] << " ";
                i++;
                j++;
            }
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        Solution ob, ob2;
        ob.unionOfArray(a, n, b, m);
        cout << endl;
        ob2.intersectionArray(a, n, b, m);
    }
    return 0;
}