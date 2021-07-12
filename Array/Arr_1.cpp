#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

class Solution
{
public:
    void reverseArray(int a[], int start, int end)
    {
        while (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
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
        int s = 0;
        int e = n - 1;
        Solution ob;
        ob.reverseArray(a, s, e);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}