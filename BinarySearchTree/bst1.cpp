TreeNode *searchBST(TreeNode *root, int val)
{

    while (root != NULL && root->val != val)
    {
        root = root->val < val ? root->right : root->left;
    }
    return root;
}