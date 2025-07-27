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

void insertAtStart(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
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

void insertAtMiddle(Node *&head, int v, int k)
{
    if (k == 1)
    {
        insertAtStart(head, v);
        return;
    }
    
    Node *temp = head;
    int count = 1;
    while (count < k - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *newNode = new Node(v);
    /*
    //MY approach
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    
    if (temp->next->next)
    {
        temp = temp->next->next;
        temp->prev = newNode;
    }
    */

    //Tutorial approach
    if(temp->next){
        temp->next->prev=newNode;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteAtStart(Node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        free(head);
        return;
    }
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void deleteAtEnd(Node* &head){
    if(head->next==NULL){
        free(head);
        return;
    }
    Node* temp=head;
    while (temp->next)
    {
        temp=temp->next;
    }
    Node* newLastNode=temp->prev;
    newLastNode->next=NULL;
    free(temp);
    
}

void deleteAtMiddle(Node* &head,int k){
    if(k==1){
        deleteAtStart(head);
        return;
    }
    Node* temp=head;
    for (int i = 1; i < k-1; i++)
    {
        temp=temp->next;
    }
    Node* deletenode=temp->next;
    temp->next=deletenode->next;
    if (deletenode->next)
    {
        deletenode->next->prev=temp;
    }
    free(deletenode);
    
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);

    n1->next = n2;
    n2->prev = n1;

    Node *head = n1;

    forwardTraversal(head);
    backwardTraversal(head);
    insertAtStart(head, 3);
    forwardTraversal(head);
    insertAtEnd(head, 4);
    forwardTraversal(head);
    insertAtMiddle(head, 5, 3);
    forwardTraversal(head);
    insertAtEnd(head,6);
    insertAtEnd(head,7);

    forwardTraversal(head);
    deleteAtStart(head);
    forwardTraversal(head);
    deleteAtEnd(head);
    forwardTraversal(head);
    deleteAtMiddle(head,3);
    forwardTraversal(head);

    return 0;
}