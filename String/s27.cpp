class Solution
{
public:
    string answer(string a, string b)
    {
        string result;
        int n1 = a.length();
        int n2 = b.length();
        for (int i = 0, j = 0; i <= n1 - 1 && j <= n2 - 1; i++, j++)
        {
            if (a[i] != b[j])
                break;
            result.push_back(a[i]);
        }
        return result;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        string a;
        a = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++)
        {
            a = answer(a, strs[i]);
        }
        return a;
    }
};