// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int findElement(int a[], int n)
    {
        int ind = 0, count = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[ind])
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count == 0)
            {
                ind = i;
                count = 1;
            }
        }
        return a[ind];
    }
    bool isMajority(int a[], int val, int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == val)
            {
                ans++;
            }
        }
        if (ans > n / 2)
        {
            return true;
        }
        return false;
    }
    int majorityElement(int a[], int size)
    {

        int val = findElement(a, size);
        bool res = isMajority(a, val, size);
        if (res == true)
        {
            return val;
        }
        return -1;
    }
    int majorityElement2(int a[], int size)
    {

        // your code here
        int x = size / 2;
        sort(a, a + size);
        int i = 0;
        while (i < size)
        {
            int j = i;
            int cnt = 0;
            while (j < size)
            {
                if (a[j] == a[i])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
                // cout<<a[j]<<" ";
                j++;
            }
            i = j;
            if (cnt > x)
            {
                return a[i - 1];
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends