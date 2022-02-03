// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        // code here
        int i = 0, j = 0;
        while (i < 2 * e - 1)
        {
            j = i + 1;

            while ((B[j] != A[i + 1] || B[j - 1] != A[i]) && i + 2 <= 2 * e - 1)
            {

                i += 2;
            }
            if (j == i + 1 && A[i + 2] == A[i])
                return 0;

            int ii = i + 1;
            int jj = j;
            while (ii >= j)
            {

                if (A[ii] != B[jj])
                    return 0;
                ii -= 2;
                jj += 2;
            }
            i += 2;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;

        cin >> n >> e;
        int A[2 * e], B[2 * e];

        for (int i = 0; i < 2 * e; i++)
            cin >> A[i];

        for (int i = 0; i < 2 * e; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n, e, A, B) << endl;
    }
    return 0;
} // } Driver Code Ends