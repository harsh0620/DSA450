#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL && head->next == NULL)
        {
            return head;
        }
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        head = reverse(head);

        Node *curr = head;
        int maxi = head->data;

        while (curr != NULL && curr->next != NULL)
        {
            if (curr->next->data < maxi)
            {
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete (temp);
            }
            else
            {
                curr = curr->next;
                maxi = curr->data;
            }
        }
        head = reverse(head);
        return head;
    }
    Node *compute1(Node *head)
    {
        Node *curr = head;

        vector<int> v;

        while (curr != NULL)
        {
            v.push_back(curr->data);
            curr = curr->next;
        }
        int maxi = v[v.size() - 1];
        for (int i = v.size() - 2; i >= 0; i--)
        {
            maxi = max(maxi, v[i]);
            v[i] = maxi;
        }
        curr = head;
        int i = 0;
        Node *newHeads = new Node(-1);
        Node *newHead = newHeads;
        while (curr != NULL)
        {
            if (v[i] > curr->data)
            {
                curr->data = -1;
            }
            else
            {
                newHead->next = new Node(curr->data);
                ;
                newHead = newHead->next;
            }
            curr = curr->next;
            i++;
        }
        return newHeads->next;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute1(head);
        print(result);
        cout << endl;
    }
}