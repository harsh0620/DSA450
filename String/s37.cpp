#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string t)
    {
        if (s.size() == 0 || t.size() == 0)
            return "-1";
        vector<int> remaining(128, 0);
        int required = t.size();
        for (int i = 0; i < required; i++)
            remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while (i <= s.size() && start < s.size())
        {
            if (required)
            {
                if (i == s.size())
                    break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0)
                    required--;
                i++;
            }
            else
            {
                if (i - start < min)
                {
                    min = i - start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0)
                    required++;
                start++;
            }
        }
        return min == INT_MAX ? "-1" : s.substr(left, min);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} // } Driver Code Ends