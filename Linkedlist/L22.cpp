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
    int pairSum(node *first, node *second, int sum)
    {
        int count = 0;

        while (first != NULL && second != NULL && first != second && second->next != first)
        {
            if (first->data + second->data == sum)
            {

                count++;
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
        return count;
    }
    int countTriplet(node *head, int sum)
    {
        if (head == NULL)
        {
            return 0;
        }
        node *first = head;
        node *last = head;
        node *current = head;
        int count = 0;

        while (last->next != NULL)
        {
            last = last->next;
        }
        for (current = head; current != NULL; current = current->next)
        {
            first = current->next;
            count += pairSum(first, last, sum - current->data);
        }
        return count;
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
        cout << ob.countTriplet(head, sum);
    }
    return 0;
}
