#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;
    Node(int d)
    {
        value = d;
        prev = NULL;
        next = NULL;
    }
};

void forwardTraversal(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << "--";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void backwardTraversal(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->value << "--";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void insertAtEnd(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void reverseDll(Node* &head){
    if(head->next==NULL){
        return;
    }
    Node* currPtr=head;
    Node* prevPtr;
    while(currPtr){
        prevPtr=currPtr->prev;
        currPtr->prev=currPtr->next;
        currPtr->next=prevPtr;
        currPtr=currPtr->prev;

    }
    head=prevPtr->prev;

}

int main(){

    Node* head=new Node(1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    
    forwardTraversal(head);
    reverseDll(head);
    forwardTraversal(head);

    return 0;
}