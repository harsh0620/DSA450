#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;

    Node(int data)
    {
        data = data;
        right = left = NULL;
    }
};
class Solution
{
public:
    void inorder(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    void preorder(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void postorder(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
    vector<int> iterativePreorder(Node *temp)
    {
        vector<int> preorder;
        if (temp == NULL)
        {
            return preorder;
        }
        stack<Node *> st;
        st.push(temp);
        while (!st.empty())
        {
            Node *node = st.top();
            st.pop();
            preorder.push_back(node->data);
            if (node->right != NULL)
            {
                st.push(node->right);
            }
            if (node->left != NULL)
            {
                st.push(node->left);
            }
        }
        return preorder;
    }
    vector<int> iterativeInorder(Node *temp)
    {
        vector<int> inorder;
        Node *node = temp;
        stack<Node *> st;
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty() == true)
                {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->data);
                node = node->right;
            }
        }
        return inorder;
    }
    vector<int> iterativePostorder(Node *temp)
    {
        vector<int> postorder;
        if (temp == NULL)
        {
            return postorder;
        }
        stack<Node *> st1, st2;
        st1.push(temp);
        while (!st1.empty())
        {
            Node *node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left != NULL)
            {
                st1.push(node->left);
            }
            if (node->right != NULL)
            {
                st1.push(node->right);
            }
        }
        while (!st2.empty())
        {
            postorder.push_back(st2.top()->data);
            st2.pop();
        }
        return postorder;
    }
};
int main()
{
    return 0;
}