#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if (str1.size() != str2.size())
        {
            return false;
        }
        int fi[MAX_CHARS] = {0};
        int se[MAX_CHARS] = {0};
        int freq[str1.size()] = {0};
        for (int i = 0; i < str1.size(); i++)
        {
            fi[str1[i] - 'a']++;
            se[str2[i] - 'a']++;
        }

        for (int i = 0; i < str1.size(); i++)
        {

            if (fi[str1[i] - 'a'] != se[str2[i] - 'a'])
            {
                return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        Solution obj;
        cout << obj.areIsomorphic(s1, s2) << endl;
    }

    return 0;
} // } Driver Code Ends