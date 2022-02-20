#include <bits/stdc++.h>

using namespace std;

bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        int arr[l];
        for (int i = 0; i < l; i++)
            cin >> arr[i];
        if (findPair(arr, l, n))
            cout << 1 << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
} // } Driver Code Ends

bool findPair(int a[], int size, int n)
{
    sort(a, a + size);
    int i = 0, j = 0;
    int k = n;
    set<int> st;
    for (int i = 0; i < size; i++)
    {
        st.insert(a[i]);
    }
    if (n == 0)
    {
        if (st.size() < size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    while (i < size)
    {
        int d = a[j] - a[i];
        if (d < k)
        {
            j++;
        }
        else if (d > k)
        {
            i++;
        }
        else if (d == k)
        {
            return true;
        }
    }
    return false;
}