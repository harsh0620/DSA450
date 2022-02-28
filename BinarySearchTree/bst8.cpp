class Solution
{
public:
    TreeNode *build(vector<int> &a, int &i, int bound)
    {
        if (i == a.size() || a[i] > bound)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(a[i++]);
        root->left = build(a, i, root->val);
        root->right = build(a, i, bound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};