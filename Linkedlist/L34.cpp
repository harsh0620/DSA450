#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        Node *start = head;
        Node *curr = head;
        vector<int> e, o;
        while (curr != NULL)
        {
            int x = curr->data;
            if (x % 2 == 0)
            {
                e.push_back(x);
            }
            else
            {
                o.push_back(x);
            }

            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < e.size(); i++)
        {
            curr->data = e[i];
            curr = curr->next;
        }
        for (int i = 0; i < o.size(); i++)
        {
            curr->data = o[i];
            curr = curr->next;
        }
        return head;
    }
};

// { Driver Code Starts.

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}