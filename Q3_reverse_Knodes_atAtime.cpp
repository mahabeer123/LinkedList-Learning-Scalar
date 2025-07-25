#include <bits/stdc++.h>
using namespace std;

// Definition of Node for a singly linked list
class Node
{
public:
    int value;      // Value to be stored in the node
    Node *next;     // Pointer to the next node in the list

    // Constructor to initialize node with given value
    Node(int v)
    {
        value = v;
        next = NULL;
    }
};

// Function to traverse (print) the linked list from head to NULL
void traverse(Node *head)
{
    Node *temp = head;                 // Start from the head node
    while (temp)
    {
        cout << temp->value << "->";   // Print the current node's value
        temp = temp->next;             // Move to the next node
    }
    cout << "NULL" << endl;            // Print NULL to indicate end of the list
}

// Function to insert a new node with value 'v' at the end of the list
void insertAtend(Node *head, int v)
{
    Node *newNode = new Node(v);       // Create a new node with value 'v'
    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head
        head = newNode;
        return;
    }
    Node *temp = head;                 // Start from head to traverse to the last node
    while (temp->next)
    {
        temp = temp->next;             // Move to the next node
    }
    temp->next = newNode;              // Set last node's next pointer to the new node
}

// Function to reverse nodes of the linked list in groups of size 'k'
Node *reverseKnodes(Node *&head, int k)
{
    // Step 1: Reverse the first 'k' nodes of the list
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    int counter = 0;
    while (curr && counter < k)
    {
        next = curr->next;         // Save the next node
        curr->next = prev;         // Reverse the current node's pointer
        prev = curr;               // Move prev one step forward
        curr = next;               // Move curr one step forward
        counter++;
    }
    // After the loop, 'curr' points to the (k+1)th node

    // Step 2: Recursively reverse the rest of the list starting from 'curr'
    if (curr)
    {
        Node *newHead = reverseKnodes(curr, k); // Reverse next group
        // Step 3: Connect the first group's tail (head) to the head of reversed next group
        head->next = newHead;
    }
    // Step 4: Return the new head of the reversed group, which is 'prev'
    return prev;
}

int main()
{
    // Create a linked list: 1->2->3->4->5->NULL
    Node *head = new Node(1);
    insertAtend(head, 2);
    insertAtend(head, 3);
    insertAtend(head, 4);
    insertAtend(head, 5);

    // Print the original list
    traverse(head);

    // Reverse in groups of 2 and print the modified list
    traverse(reverseKnodes(head, 2));
    return 0;
}
