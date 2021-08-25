#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
node *insertBegin(node *head, int x)
{
    node *temp = new node(x);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    return temp;
}

void displayLL(node *head)
{
    if (head == NULL)
    {
        cout << "UNDERFLOW" << endl;
        return;
    }
    node *temp = head->next;
    cout << head->data << " ";
    while (temp != NULL && temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution
{
public:
    node *breakCllK(node *head, int k)
    {
        node *temp = head;
        int count = 0;

        while (temp != NULL && count < k)
        {
            temp = temp->next;
            count++;
        }
        // cout << temp->data << endl;
        temp->prev->next = NULL;
        temp->prev = NULL;

        return temp;
    }
    node *reverseDLL(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *prev = NULL;
        node *curr = head;
        while (curr != NULL)
        {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        // cout << head->data << endl;
        head->next = prev->prev;
        prev->prev->prev = head;
        return prev->prev;
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
        int k;
        cin >> k;
        displayLL(head);
        cout << endl;
        Solution ob;
        head = ob.reverseDLL(head);
        head = ob.breakCllK(head, k);

        displayLL(head);
        cout << endl;
    }
    return 0;
}
