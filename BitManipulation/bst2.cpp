#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int Xor = 0;
        for (int i = 0; i < nums.size(); i++)
            Xor ^= nums[i];

        int posi = __builtin_clz(Xor);
        int A = 0, B = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            string s = bitset<32>(nums[i]).to_string();
            if (s[posi] == '0')
                A ^= nums[i];
            else
                B ^= nums[i];
        }
        return {min(A, B), max(A, B)};
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends