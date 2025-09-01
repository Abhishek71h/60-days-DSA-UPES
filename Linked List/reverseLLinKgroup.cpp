#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    Node() {
        this -> data = 0;
        this -> next = NULL;
    }

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        cout << "Node with value " << this->data << " deleted" << endl;
    }
};

void PrintLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node* &head) {
    int length = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp -> next;
        length++;
    }
    return length;
}

Node* reverseKLL(Node* &head, int k) {
    if(head == NULL) {
        cout << "Linked List is empty, can't reverse it" << endl;
        return NULL;
    }
    int len = getLength(head);
    if(k > len) {
        return head;
    }

    int count = 0;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(count < k) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if(forward != NULL) {
        head -> next = reverseKLL(forward, k);
    }
    return prev;
}


int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = NULL;
    PrintLL(head);
    cout << endl;

    head = reverseKLL(head, 3);
    PrintLL(head);
    return 0;
}