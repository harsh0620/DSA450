#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[low++], a[mid++]);
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else if (a[mid] == 2)
            {
                swap(a[mid], a[high--]);
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}