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
    void pairSum(node *head, int sum)
    {
        node *first = head;
        node *second = head;
        while (second->next != NULL)
        {
            second = second->next;
        }
        bool found = false;

        while (first != second && second->next != first)
        {
            if (first->data + second->data == sum)
            {
                found = true;
                cout << first->data << "," << second->data << endl;
                first = first->next;
                second = second->prev;
            }
            else
            {
                if (first->data + second->data < sum)
                {
                    first = first->next;
                }
                else
                {
                    second = second->prev;
                }
            }
        }
        if (found == false)
        {
            cout << "NO Pairs" << endl;
            return;
        }
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
        int sum;
        cin >> sum;
        displayLL(head);
        cout << endl;
        Solution ob;
        ob.pairSum(head, sum);
    }
    return 0;
}
