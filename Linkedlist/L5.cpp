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
void loopHere(node *head, node *tail, int position)
{
    if (position == 0)
    {
        return;
    }
    node *walk = head;
    for (int i = 1; i < position; i++)
    {
        walk = walk->next;
    }
    tail->next = walk;
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
    bool detectLoop(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        node *slow = head;
        node *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
    node *firstPointerofLoop(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        node *slow = head;
        node *fast = head;
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                if (slow == head)
                {
                    while (slow->next != head)
                    {
                        slow = slow->next;
                    }
                    return (slow->next);
                }
                if (slow == fast)
                {
                    slow = head;
                    while (slow->next != fast->next)
                    {
                        if (slow == fast->next)
                        {
                            fast->next = NULL;
                        }
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return (fast->next);
                }
            }
        }
        return NULL;
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
        node *head, *tail;
        int num;
        cin >> num;
        head = tail = new node(num);
        for (int i = 0; i < n - 1; i++)
        {
            int x;
            cin >> x;
            tail->next = new node(x);
            tail = tail->next;
        }
        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        Solution ob;
        cout << ob.firstPointerofLoop(head) << endl;
    }
    return 0;
}
