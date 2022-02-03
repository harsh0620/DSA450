#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
    int data;
    struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node *newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int getGrandChildren(node *node);
int getMaxAnswer(node *node, map<struct node *, int> &mp);

int getGrandChildren(node *node, map<struct node *, int> &mp)
{
    int sum = 0;

    //  call for children of left child only if it is not NULL
    if (node->left)
        sum += getMaxAnswer(node->left->left, mp) +
               getMaxAnswer(node->left->right, mp);

    //  call for children of right child only if it is not NULL
    if (node->right)
        sum += getMaxAnswer(node->right->left, mp) +
               getMaxAnswer(node->right->right, mp);

    return sum;
}
int getMaxAnswer(node *root, map<struct node *, int> &mp)
{
    if (root == NULL)
    {
        return 0;
    }
    if (mp.find(root) != mp.end())
    {
        return mp[root];
    }
    int incl = root->data + getGrandChildren(root, mp);
    int excl = getMaxAnswer(root->left, mp) + getMaxAnswer(root->right, mp);

    mp[root] = max(incl, excl);
    return mp[root];
}
int getMaxSum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    map<struct node *, int> mp;
    int ans = getMaxAnswer(root, mp);
    return ans;
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);

    cout << getMaxSum(root) << endl;
    return 0;
}