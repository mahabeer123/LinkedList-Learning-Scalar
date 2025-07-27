/*
QUESTION:- GIVEN A SORTED DOUBLY LINKEDLIST, REMOVE ALL THE DUPLICATE VALUES PRESENT IN THE LIST.
INPUT:- 4<->4<->7<->7<->7<->10
OUTPUT:- 4<->7<->10
*/

#include<bits/stdc++.h>
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

void deleteNode(Node* &head, Node* delNode){
    if(head==NULL || delNode==NULL){
        return;
    }
    Node* prevNode=delNode->prev;
    Node* nextNode=delNode->next;

    if(prevNode){
        //delNode is not the first node
        prevNode->next=nextNode;
    }
    if(nextNode){
        //delNode is not the last node
        nextNode->prev=prevNode;
    }
    free(delNode);
}

void removeDuplicate(Node* &head){
    Node* curr=head;
    while(curr->next){
        if(curr->value==curr->next->value){
            //delete the 'curr->next' node
            deleteNode(head,curr->next);
        }
        else{
            curr=curr->next;
        }
    }
}

int main(){
    Node* head=new Node(1);
    insertAtEnd(head,4);
    insertAtEnd(head,4);
    insertAtEnd(head,7);
    insertAtEnd(head,7);
    insertAtEnd(head,7);
    insertAtEnd(head,10);

    forwardTraversal(head);

    removeDuplicate(head);

    forwardTraversal(head);

    return 0;


}
