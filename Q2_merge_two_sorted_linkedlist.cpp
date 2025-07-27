#include <bits/stdc++.h>
using namespace std;

// Node class representing one element in a singly linked list
class Node
{
public:
    int value;      // The value/data stored in the node
    Node *next;     // Pointer to the next node in the list

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
    Node *temp = head;   // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        cout << temp->value << "->";  // Print current node's value followed by arrow
        temp = temp->next;            // Move to the next node
    }
    cout << "NULL" << endl;           // Print NULL at end, indicating list termination
}

// Function to insert a node with given value at the end of the linked list
// The head pointer is passed by reference to allow modification when list is empty
void insertAtEnd(Node *&head, int val)
{
    Node *n = new Node(val);    // Create a new node with given value

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

/* 
 * Your original merge approach to merge two sorted linked lists.
 * Accepts head references to two sorted linked lists
 * Returns the head of a newly merged (also sorted) linked list by rearranging existing nodes.
 */
Node *mergell(Node *&head1, Node *&head2)
{
    // If one of the lists is empty, return the other as the merged list
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *newHead;  // Pointer to the head of the merged list

    // Initialize newHead to point to the smaller first node
    if (head1->value <= head2->value)
    {
        newHead = head1;
        head1 = head1->next;       // Move forward in list1
    }
    else
    {
        newHead = head2;
        head2 = head2->next;       // Move forward in list2
    }

    Node *temp = newHead;          // Pointer to build merged list

    // Merge nodes one by one until either list runs out
    while (head1 && head2)
    {
        if (head1->value <= head2->value)
        {
            temp->next = head1;     // Link smaller node from list1
            head1 = head1->next;    // Advance in list1
        }
        else
        {
            temp->next = head2;     // Link smaller node from list2
            head2 = head2->next;    // Advance in list2
        }
        temp = temp->next;          // Move pointer forward in merged list
    }

    // Append any remaining nodes from list1
    if (head1)
    {
        while (head1)
        {
            temp->next = head1;
            temp = temp->next;      // IMPORTANT: Move merged list pointer forward
            head1 = head1->next;
        }
    }
    else // Append remaining nodes from list2
    {
        while (head2)
        {
            temp->next = head2;
            temp = temp->next;      // IMPORTANT: Move merged list pointer forward
            head2 = head2->next;
        }
    }

    return newHead;  // Return head of the merged, sorted linked list
}

/*
 * Tutorial merge approach using dummy node to simplify merging.
 * Dummy nodes help avoid special cases for head initialization.
 */
Node *mergeLinkedLists(Node *head1, Node *head2)
{
    Node *dummyHeadNode = new Node(-1);  // Temporary dummy node
    Node *tail = dummyHeadNode;           // Pointer to track end of merged list

    // Traverse both lists, appending smaller node each time
    while (head1 && head2)
    {
        if (head1->value < head2->value)
        {
            tail->next = head1;    // Link smaller node from list1
            head1 = head1->next;   // Advance in list1
        }
        else
        {
            tail->next = head2;    // Link smaller node from list2
            head2 = head2->next;   // Advance in list2
        }
        tail = tail->next;          // Advance tail pointer in merged list
    }

    // Append remaining nodes from list1 or list2 if any
    if (head1)
        tail->next = head1;

    if (head2)
        tail->next = head2;

    Node *mergedHead = dummyHeadNode->next; // Actual start of merged list (after dummy)
    delete dummyHeadNode;                   // Delete dummy node to avoid memory leak
    return mergedHead;                      // Return merged list head
}

int main()
{
    Node *head1 = NULL;    // Head of first linked list
    Node *head2 = NULL;    // Head of second linked list

    // Insert values into first linked list (sorted)
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 5);
    insertAtEnd(head1, 6);

    // Insert values into second linked list (sorted)
    insertAtEnd(head2, 3);
    insertAtEnd(head2, 4);

    cout << "List 1: ";
    traverse(head1);         // Display first list

    cout << "List 2: ";
    traverse(head2);         // Display second list

    // Uncomment the desired merge method:

    // Using your original merge approach:
    // Node *mergedHead = mergell(head1, head2);

    // Using tutorial dummy-node merge approach:
    Node *mergedHead = mergeLinkedLists(head1, head2);

    cout << "Merged List: ";
    traverse(mergedHead);    // Display merged list

    return 0;
}
