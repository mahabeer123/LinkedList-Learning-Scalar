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

//Traversal-In-Loop
void traversalInLoop(Node* head){
    Node* temp=head;
    int k=10;
    while(k--){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtStart(Node* &head,int v){
    Node* newNode=new Node(v);
    if(head==NULL){
        head=newNode;
        head->next=head;
        return;
    }
    Node* temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newNode; //changing the look from the last node to the head node
    newNode->next=head; //making the new node point to current head node
    head=newNode; //updating the head node
    
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

void deleteAtStart(Node* &head){
    Node* temp=head;
    if(head==NULL){
        return;
    }
    if(head->next==head){
        free(head);
        return;
    }
    Node* tail=head;
    while (tail->next!=head)
    {
        tail=tail->next;
    }
    tail->next=head->next;
    head=head->next;
    free(temp);
    
}

void deleteAtEnd(Node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        free(head);
        return;
    }
    Node* secondLast=head;
    while(secondLast->next->next!=head){
        secondLast=secondLast->next;
    }
    Node* last=secondLast->next;
    secondLast->next=head;
    free(last);
}

int main(){
    Node* n1=new Node(1);
    Node* n2=new Node(2);

    n1->next=n2;
    n2->next=n1;

    Node* head=n1;

    traversal(head);

    // traversalInLoop(head);

    // Node* head= new Node(1);

    insertAtStart(head,2);
    traversal(head);

    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);

    traversal(head);

    deleteAtStart(head);

    traversal(head);

    deleteAtEnd(head);

    traversal(head);




    return 0;
}