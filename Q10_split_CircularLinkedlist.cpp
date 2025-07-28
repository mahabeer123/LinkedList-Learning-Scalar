/*
QUESTION:- GIVEN A CIRCULAR LINKEDLIST, SPLIT IT INTO TWO HALVES. IF THERE 
    ARE ODD NUMBER OF NODES, THEN FIRST LIST SHOULD CONTAIN ONE EXTRA.
INPUT:- 1->2->3->4->
OUTPUT:- 1->2->
         3->4->
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node(int d){
        value=d;
        next=NULL;
    }
};

void traversal(Node* head){
    Node* temp=head;
    do
    {
        cout<<temp->value<<"->";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
    
}

void insertAtEnd(Node* &head,int v){
    Node* newNode=new Node(v);
    if(head==NULL){
        head=newNode;
        head->next=head;
        return;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
}

void splitLinkedlist(Node* &head){
    if(head->next==head){
        // head1=head;
        return;
    }
    //find the middle node
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    //placing the new head poniters
    Node* head1=head;
    Node* head2=slow->next;
    //in case of even nodes, we will move the fast pointerto last node
    if(fast->next->next==head){
        fast=fast->next;
    }
    //making the last nodes point to the head nodes
    slow->next=head1;
    fast->next=head2;


    traversal(head1);
    traversal(head2);
}

int main(){
    Node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    

    traversal(head);

    splitLinkedlist(head);
    // traversal(head);


}
