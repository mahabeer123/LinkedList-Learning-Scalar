#include <bits/stdc++.h>
using namespace std;

// Node class representing one element in a singly linked list
class Node
{
public:
    int value;  // The value/data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor to create a node with a given value
    // By default, sets next pointer to NULL indicating end of list
    Node(int v)
    {
        value = v;
        next = NULL;
    }
};

// Function to print all elements of the linked list starting from 'head'
void traverse(Node *head)
{
    Node *temp = head; // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        cout << temp->value << "->"; // Print current node's value followed by arrow
        temp = temp->next;           // Move to the next node
    }
    cout << "NULL" << endl; // Print NULL at end, indicating list termination
}

// Function to insert a node with given value at the end of the linked list
// The head pointer is passed by reference to allow modification when list is empty
void insertAtEnd(Node *&head, int val)
{
    Node *n = new Node(val); // Create a new node with given value

    // If list is empty, new node becomes the head
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    // Traverse to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Link new node at the end
    temp->next = n;
}

Node *createll(int n)
{
    if (n <= 0)
        return nullptr; // If no nodes requested, return empty list

    int val;
    cin >> val;                 // Read first node value
    Node *head = new Node(val); // Create head node
    Node *temp = head;

    // Read remaining values and add nodes at the end
    for (int i = 1; i < n; i++)
    {
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }

    return head; // Return pointer to head of created list
}

int getLength(Node *head)
{
    Node *temp = head;
    int n = 1;
    while (temp)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

Node *moveKsteps(Node *head, int k)
{
    Node *temp = head;
    while (k--)
    {
        temp = temp->next;
    }
    return temp;
}

Node *getIntersectionNode(Node *head1, Node *head2)
{
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    Node *temp1;
    Node *temp2;

    if (l1 > l2)
    {
        int k = l1 - l2;
        temp1 = moveKsteps(head1, k);
        temp2 = head2;
    }
    else
    {
        int k = l2 - l1;
        temp1 = head1;
        temp2 = moveKsteps(head2, k);
    }
    while (temp1 && temp2)
    {
        if (temp1 == temp2)
        {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

int main()
{
    Node *head1 = new Node(1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 4);

    Node *head2 = new Node(5);
    insertAtEnd(head2, 6);

    head2->next->next = head1->next->next;
    traverse(head1);
    traverse(head2);
    cout << getIntersectionNode(head1, head2)->value << endl;
    ;

    return 0;
}