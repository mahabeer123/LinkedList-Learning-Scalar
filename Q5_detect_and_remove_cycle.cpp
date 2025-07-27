#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int d)
    {
        value = d;
        next = NULL;
    }
};

// Function to traverse (print) the linked list from head to NULL
void traverse(Node *head)
{
    Node *temp = head; // Start from the head node
    while (temp)
    {
        cout << temp->value << "->"; // Print the current node's value
        temp = temp->next;           // Move to the next node
    }
    cout << "NULL" << endl; // Print NULL to indicate end of the list
}

// Function to insert a new node with value 'v' at the end of the list
void insertAtend(Node *head, int v)
{
    Node *newNode = new Node(v); // Create a new node with value 'v'
    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head
        head = newNode;
        return;
    }
    Node *temp = head; // Start from head to traverse to the last node
    while (temp->next)
    {
        temp = temp->next; // Move to the next node
    }
    temp->next = newNode; // Set last node's next pointer to the new node
}

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main()
{
    Node *head = new Node(1);
    insertAtend(head, 2);
    insertAtend(head, 3);
    insertAtend(head, 4);
    insertAtend(head, 5);

    head->next->next->next->next->next = head->next->next;
    cout << detectCycle(head) << endl;
    removeCycle(head);
    traverse(head);
    return 0;
}