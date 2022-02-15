#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    void leftToRight(string needle, string input[], int n, int m, int &ans)
    {
        auto ind = 0;
        for (int i = 0; i < n; i++)
        {
            string x = "";
            for (int j = 0; j < m; j++)
            {
                x += input[i][j];
            }
            bool flag = false;
            auto tmp = x.find(needle);

            if (tmp != string::npos)
            {
                ind = tmp;
                flag = true;
                ans++;
            }
            if (flag == true)
            {
                for (int j = ind; j <= needle.size(); j++)
                {
                    input[i][j] = '0';
                }
            }
        }
    }
    void rightToLeft(string needle, string input[], int n, int m, int &ans)
    {

        for (int i = n - 1; i >= 0; i--)
        {
            string x;
            for (int j = m - 1; j >= 0; j--)
            {
                x.push_back(input[i][j]);
            }
            bool flag = false;
            size_t tmp = x.find(needle);

            if (tmp != string::npos)
            {

                flag = true;
                ans++;
            }
            if (flag == true)
            {
                for (int j = m - 1 - tmp; j >= m - needle.length(); j--)
                {
                    input[i][j] = '0';
                }
            }
        }
    }
    void topToDown(string needle, string input[], int n, int m, int &ans)
    {
        auto ind = 0;
        for (int i = 0; i < n; i++)
        {
            string x = "";
            for (int j = 0; j < m; j++)
            {
                x += input[j][i];
            }
            bool flag = false;
            auto tmp = x.find(needle);

            if (tmp != string::npos)
            {
                ind = tmp;
                flag = true;
                ans++;
            }
            if (flag == true)
            {
                for (int j = ind; j <= needle.size(); j++)
                {
                    input[j][i] = '0';
                }
            }
        }
    }
    void downToTop(string needle, string input[], int n, int m, int &ans)
    {

        for (int i = n - 1; i >= 0; i--)
        {
            string x;
            for (int j = m - 1; j >= 0; j--)
            {
                x.push_back(input[j][i]);
            }
            bool flag = false;
            size_t tmp = x.find(needle);

            if (tmp != string::npos)
            {

                flag = true;
                ans++;
            }
            if (flag == true)
            {
                for (int j = m - 1 - tmp; j >= m - needle.length(); j--)
                {
                    input[j][i] = '0';
                }
            }
        }
    }
    int answer(string needle, string input[], int n, int m)
    {

        int ans = 0;
        rightToLeft(needle, input, n, m, ans);
        leftToRight(needle, input, n, m, ans);
        topToDown(needle, input, n, m, ans);
        downToTop(needle, input, n, m, ans);

        return ans;
    }
};
int main()
{
    string needle = "MAGIC";
    string input[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABBBBC",
                      "MCIGAM"};
    int n = 6, m = 6;
    Solution ob;
    cout << ob.answer(needle, input, n, m);

    return 0;
}