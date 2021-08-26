#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
public:
    //Function to merge K sorted linked list.
    Node *Smerge(Node *a, Node *b)
    {
        Node *result = NULL;

        /* Base cases */
        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        /* Pick either a or b, and recur */
        if (a->data <= b->data)
        {
            result = a;
            result->next = Smerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = Smerge(a, b->next);
        }

        return result;
    }
    Node *mergeKLists(Node *arr[], int K)
    {

        int i = 0;
        int last = K - 1;
        int j;
        while (last != 0)
        {
            i = 0;
            j = last;
            while (i < j)
            {
                arr[i] = Smerge(arr[i], arr[j]);
                i++;
                j--;
                if (i >= j)
                {
                    last = j;
                }
            }
        }

        return arr[0];
    }
};

// { Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}