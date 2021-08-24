#include <bits/stdc++.h>
using namespace std;

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
node *insertHead(node *head, int data)
{
    node *temp = new node(data);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int x = temp->data;
        temp->data = head->data;
        head->data = x;
        return head;
    }
}
node *deleteHeadCLL(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {

        head->data = head->next->data;
        node *temp = head->next;
        head->next = head->next->next;
        delete temp;
        return head;
    }
}
node *deleteKthCLL(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (k == 1)
    {
        return deleteHeadCLL(head);
    }
    node *curr = head;
    for (int i = 0; i < k - 2; i++)
    {
        curr = curr->next;
    }
    node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
void displayCLL(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    for (node *i = head->next; i != head; i = i->next)
    {
        cout << i->data << " ";
    }
}

int main()
{
    node *head = NULL;
    head = insertHead(head, 40);
    head = insertHead(head, 30);
    head = insertHead(head, 20);
    head = insertHead(head, 10);
    head = deleteKthCLL(head, 3);
    displayCLL(head);

    return 0;
}
