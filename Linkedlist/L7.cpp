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
    node *removeDuplicatesUnsorted(node *head)
    {
        unordered_set<int> seen;

        /* Pick elements one by one */
        node *curr = head;
        node *prev = NULL;
        while (curr != NULL)
        {
            // If current value is seen before
            if (seen.find(curr->data) != seen.end())
            {
                prev->next = curr->next;
                delete (curr);
            }
            else
            {
                seen.insert(curr->data);
                prev = curr;
            }
            curr = prev->next;
        }
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
        int k;
        cin >> k;
        displayLL(head);
        cout << endl;
        Solution ob;
        head = ob.removeDuplicatesUnsorted(head);
        displayLL(head);
    }
    return 0;
}
