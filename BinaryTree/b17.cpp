#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;

    // Node(int data)
    // {
    //     data = data;
    //     right = left = NULL;
    // }
};
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void preOrder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
int findIndex(string str, int si, int ei)
{
    if (si > ei)
    {
        return -1;
    }
    stack<char> s;
    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}
Node *treeFromString(string s, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int x = (s[si] - '0');
    Node *root = newNode(x);
    int index = -1;

    if (si + 1 <= ei && s[si + 1] == '(')
    {
        index = findIndex(s, si + 1, ei);
    }
    if (index != -1)
    {
        root->left = treeFromString(s, si + 2, index - 1);
        root->right = treeFromString(s, index + 2, ei - 1);
    }
    return root;
}
int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node *root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
    return 0;
}