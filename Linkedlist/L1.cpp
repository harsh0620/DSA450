#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *insertBegin(node *head, int x)
{
    node *temp = new node(x);
    temp->next = head;
    return temp;
}

void displayLL(node *head)
{
    if (head == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
class Solution
{
public:
    node *reverseLLNaive(node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        vector<int> v;

        for (node *curr = head; curr != NULL; curr = curr->next)
        {
            v.push_back(curr->data);
        }

        for (node *curr = head; curr != NULL; curr = curr->next)
        {
            curr->data = v.back();
            v.pop_back();
        }
        return head;
    }
    node *reverseLLEfficient(node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        node *curr = head;
        node *prev = NULL;

        while (curr != NULL)
        {
            node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    node *reverseLLRecursive1(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *restHead = reverseLLRecursive1(head->next);
        node *restTail = head->next;

        restTail->next = head;
        head->next = NULL;
        return restHead;
    }

    node *reverseLLRecursive2(node *curr, node *prev)
    {
        if (curr == NULL)
        {
            return prev;
        }
        node *nextt = curr->next;
        curr->next = prev;
        return reverseLLRecursive2(nextt, curr);
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        node *head = NULL;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            head = insertBegin(head, x);
        }
        displayLL(head);
        Solution ob;
        head = ob.reverseLLNaive(head);
        displayLL(head);
    }
    return 0;
}