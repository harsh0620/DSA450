#include <bits/stdc++.h>
using namespace std;

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {

        cin >> n;
        n = n - 1;
        cin >> x;
        node *temp, *head = new node(x);
        temp = head;
        while (n--)
        {
            cin >> x;
            temp->next = new node(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
} // } Driver Code Ends

/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int a[], int l, int h)
{
    int i = l;
    int j = h;
    int pivot = a[l];
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[j]);
    return j;
}
void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(a, l, h);
        quickSort(a, l, pi);
        quickSort(a, pi + 1, h);
    }
}
void quickSort(struct node **headRef)
{

    node *curr = *headRef;
    // cout<<curr->data<<endl;
    int a[202] = {0};
    int i = 0, cnt = 0;
    while (curr != NULL)
    {
        a[i] = curr->data;
        i++;
        cnt++;
        curr = curr->next;
    }
    quickSort(a, 0, cnt);
    node *temp = *headRef;
    for (int i = 0; i < cnt; i++)
    {
        temp->data = a[i];
        temp = temp->next;
    }
    // cout<<endl;
}