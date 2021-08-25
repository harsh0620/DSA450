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
    node *rotateByN(node *head, int k)
    {
        if (head == NULL)
        {
            return head;
        }
        if (k == 0)
        {
            return head;
        }

        node *temp = head;
        node *newHead = head;
        int cnt = 0;
        while (temp->next != NULL)
        {
            if (cnt == k)
            {
                newHead = temp;
            }
            temp = temp->next;
            cnt++;
        }
        temp->next = head;
        head->prev = temp;

        newHead->prev->next = NULL;
        newHead->prev = NULL;
        return newHead;
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
        head = ob.rotateByN(head, k);
        displayLL(head);
        cout << endl;
    }
    return 0;
}
