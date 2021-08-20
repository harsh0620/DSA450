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
    node *newnode(int data)
    {
        node *new_node = new node(data);
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
    }
    node *reverse(node *head)
    {
        node *prev = NULL;
        node *current = head;
        node *next;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    node *addOneUtil(node *head)
    {

        node *res = head;
        node *temp, *prev = NULL;

        int carry = 1, sum;

        while (head != NULL)
        {

            sum = carry + head->data;

            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            head->data = sum;
            temp = head;
            head = head->next;
        }
        if (carry > 0)
            temp->next = newnode(carry);

        return res;
    }
    node *addOne(node *head)
    {
        head = reverse(head);
        head = addOneUtil(head);
        return reverse(head);
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
        head = ob.addOne(head);
        displayLL(head);
    }
    return 0;
}
