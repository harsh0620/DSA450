#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countSquares(int N)
    {
        int k = sqrt(N);

        if (k * k == N)
        {
            return k - 1;
        }
        else
        {
            return k;
        }
    }
    int countSquaresEfficient(int b)
    {
        return (floor(sqrt(b)) - ceil(sqrt(2)) + 1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.countSquaresEfficient(N) << endl;
    }
    return 0;
} // } Driver Code Ends