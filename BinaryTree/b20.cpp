#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    Node *buildTree(int in[], int is, int ie, int pre[], int ps, int pe, map<int, int> &inMap)
    {
        if (is > ie || ps > pe)
        {
            return NULL;
        }
        Node *root = new Node(pre[ps]);
        int inRoot = inMap[root->data];
        int numLeft = inRoot - is;

        root->left = buildTree(in, is, inRoot - 1, pre, ps + 1, ps + numLeft, inMap);
        root->right = buildTree(in, inRoot + 1, ie, pre, ps + numLeft + 1, pe, inMap);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        map<int, int> inMap;
        for (int i = 0; i < n; i++)
        {
            inMap[in[i]] = i;
        }
        Node *res = buildTree(in, 0, n - 1, pre, 0, n - 1, inMap);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends