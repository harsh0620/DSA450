#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *l1, struct Node *l2)
    {
        stack<int> s1, s2;
        while (l1 != NULL)
        {
            s1.push(l1->data);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            s2.push(l2->data);
            l2 = l2->next;
        }
        int carry = 0;
        Node *result = NULL;
        while (s1.empty() == false || s2.empty() == false)
        {
            int a = 0, b = 0;
            if (s1.empty() == false)
            {
                a = s1.top();
                s1.pop();
            }
            if (s2.empty() == false)
            {
                b = s2.top();
                s2.pop();
            }
            int total = a + b + carry;
            Node *temp = new Node(total % 10);
            temp->data = total % 10;
            carry = total / 10;
            if (result == NULL)
            {
                result = temp;
            }
            else
            {
                temp->next = result;
                result = temp;
            }
        }
        if (carry != 0)
        {
            Node *temp = new Node(carry);
            temp->data = carry;
            temp->next = result;
            result = temp;
        }
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends