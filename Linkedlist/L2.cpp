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
    node *reverse(node *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        node *curr = head;
        node *firstHead = head;
        node *prev = NULL;
        node *temp = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        if (temp != NULL)
            head->next = reverse(temp, k);
        return prev;
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
        Solution ob;
        head = ob.reverse(head, k);
        displayLL(head);
    }
    return 0;
}