#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* The structure of the binary tree is as follows
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
    /*You are required to complete this method*/
    void returnLeaf(Node *root, vector<int> &v)
    {
        if (root != NULL)
        {
            if (root->left == NULL && root->right == NULL)
            {
                v.push_back(root->data);
            }
            returnLeaf(root->left, v);
            returnLeaf(root->right, v);
        }
    }

    bool check(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        vector<int> v;
        returnLeaf(root, v);
        queue<Node *> q;
        q.push(root);
        vector<vector<int>> answer;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                q.pop();
                tmp.push_back(temp->data);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            answer.push_back(tmp);
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for (int i = 0; i < answer[answer.size() - 1].size(); i++)
        {
            res.push_back(answer[answer.size() - 1][i]);
        }
        sort(res.begin(), res.end());
        if (v.size() != res.size())
        {
            return false;
        }
        for (int i = 0; i < max(v.size(), res.size()); i++)
        {
            if (v[i] != res[i])
            {
                return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}
// } Driver Code Ends