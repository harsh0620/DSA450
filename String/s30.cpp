
// } Driver Code Ends
class Solution
{
public:
    int minimumNumberOfSwaps(string S)
    {
        // code here
        int ans = 0;
        int cnt = 0;
        int n = S.length();
        for (int i = 0; i < n; i++)
        {
            if (S[i] == '[')
            {
                cnt--;
            }
            else
            {
                cnt++;
                if (cnt > 0)
                {
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
} // } Driver Code Ends