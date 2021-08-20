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
    node *moveToFront(node *head)
    {
        if (head == NULL && head->next == NULL)
        {
            return head;
        }
        node *secL = NULL;
        node *last = head;
        while (last->next != NULL)
        {
            secL = last;
            last = last->next;
        }
        secL->next = NULL;
        last->next = head;
        head = last;
        return head;
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
        cout << endl;
        Solution ob;
        head = ob.moveToFront(head);
        displayLL(head);
    }
    return 0;
}
