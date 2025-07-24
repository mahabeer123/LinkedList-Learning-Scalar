#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void ib(Node*& head, int val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void ie(Node*& head, int val) {
    if (head == NULL) {
        ib(head, val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}


void im(Node*& head, int val, int k) {
    if (k == 1) {
        ib(head, val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;
    int position = 1;
    while (position < k - 1) {
        temp = temp->next;
        position++;
    }
    n->next = temp->next;
    temp->next = n;
}

void db(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    free(temp);
}

void de(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        db(head);
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* curr = temp;
    temp = temp->next;
    curr->next = NULL;
    free(temp);
}

void dm(Node*& head, int k) {
    if (head == NULL) return;
    if (k == 1) {
        db(head);
        return;
    }
    Node* temp = head;
    int position = 1;
    while (position < k - 1) {
        temp = temp->next;
        position++;
    }
    Node* curr = temp;
    temp = temp->next;
    curr->next = temp->next;
    free(temp);
}

void ub(Node*& head, int val) {
    head->value = val;
}

void ue(Node*& head, int val) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->value = val;
}

void um(Node*& head, int val, int k) {
    if (k == 1) {
        ub(head, val);
        return;
    }
    Node* temp = head;
    int position = 1;
    while (position < k) {
        temp = temp->next;
        position++;
    }
    temp->value = val;
}

void deleteAlternateNode(Node*& head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        Node* n = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(n);
    }
}

void findMiddleElement(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->value << endl;
}

void reverseLinkedlist(Node*& head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* temp;

    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

void checkPallindrome(Node* head) {
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* prev = NULL;
    Node* curr = slow;
    Node* temp;

    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    Node* start = head;
    Node* end = prev;

    while (end != NULL) {
        if (start->value != end->value) {
            cout << "Not a palindrome" << endl;
            return;
        }
        start = start->next;
        end = end->next;
    }
    cout << "Palindrome Linked-list" << endl;
}

void rotateLinkedlist(Node*& head, int k) {
    if (!head || k == 0) return;

    Node* c = head;
    int n = 1;
    while (c->next) {
        n++;
        c = c->next;
    }

    k = k % n;
    if (k == 0) return;

    Node* temp = head;
    Node* r = head;
    int count = 1;

    while (temp->next != NULL) {
        if (count < n - k) {
            r = r->next;
            count++;
        }
        temp = temp->next;
    }

    temp->next = head;
    head = r->next;
    r->next = NULL;
}

// Empty function in original code
// void(Node* head1, Node* head2) {}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* head = n1;
    n1->next = n2;

    ib(head, 6);
    ie(head, 3);
    im(head, 5, 3);
    db(head);
    de(head);
    dm(head, 2);

    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n2->next = n3;
    n3->next = n4;

    ub(head, 5);
    ue(head, 6);
    um(head, 7, 3);

    ib(head, 1);
    ie(head, 8);
    ie(head, 15);

    traverse(head);
    findMiddleElement(head);

    reverseLinkedlist(head);
    traverse(head);

    cout << endl << "New Execution" << endl;

    Node* n5 = new Node(1);
    Node* head1 = n5;
    ie(head1, 3);
    ie(head1, 5);
    ie(head1, 3);
    ie(head1, 1);
    // checkPallindrome(head1);

    rotateLinkedlist(head, 2);
    traverse(head);

    return 0;
}