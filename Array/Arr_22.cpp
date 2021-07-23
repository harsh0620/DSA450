#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int MAX = 100000;

    vector<int> factorial(int N)
    {
        // code here
        int res[MAX];
        vector<int> ans;
        // Initialize result
        res[0] = 1;
        int res_size = 1;

        // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
        for (int x = 2; x <= N; x++)
        {
            int carry = 0; // Initialize carry

            // One by one multiply n with individual digits of res[]
            for (int i = 0; i < res_size; i++)
            {
                int prod = res[i] * x + carry;

                // Store last digit of 'prod' in res[]
                res[i] = prod % 10;

                // Put rest in carry
                carry = prod / 10;
            }

            // Put carry in res and increase result size
            while (carry)
            {
                res[res_size] = carry % 10;
                carry = carry / 10;
                res_size++;
            }
        }

        for (int i = res_size - 1; i >= 0; i--)
        {
            ans.push_back(res[i]);
        }

        return ans;
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
        Solution ob;
        vector<int> ans = ob.factorial(n);
        for (auto x : ans)
        {
            cout << x;
        }
        cout << endl;
    }
    return 0;
}
