#include <bits/stdc++.h>
using namespace std;

void inorder(int a[], vector<int> &v, int n, int index)
{
    if (index >= n)
    {
        return;
    }
    inorder(a, v, n, 2 * index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}
void swap(vector<int> &v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int minSwaps(vector<int> v)
{
    map<int, int> mp;
    int ans = 0;
    vector<int> temp(v.begin(), v.end());
    int n = v.size();
    sort(temp.begin(), temp.end());
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] != temp[i])
        {
            ans++;
            int tmp = v[i];
            swap(v, i, mp[temp[i]]);
            mp[tmp] = mp[temp[i]];
            mp[temp[i]] = i;
        }
    }
    return ans;
}
int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
    return 0;
}