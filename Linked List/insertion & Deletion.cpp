// Insertion & Deletion of Singly Linked List

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

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

int lengthofLL(Node* &head) {
    int length = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp -> next;
        length++;
    }
    return length;
}

void insertAtPosition(int position, Node* &head, Node* &tail, int data) {
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }
    int len = lengthofLL(head);
    if(position >= len) {
        insertAtTail(tail, data);
        return;
    }
    int count = 1;
    Node* prev = head;
    while(count < position-1) {
        prev = prev -> next;
        count++;
    }
    Node* curr = prev -> next;
    Node* newNode = new Node(data);
    newNode -> next = curr;
    prev -> next = newNode;
}

void deleteNode(int position, Node* &head, Node* &tail) {
    if(head == NULL) {
        cout << "No Deletion happen";
        return;
    }
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = lengthofLL(head); 
    if(position > len || position <= 0) {
        cout << "Invalid No deletion" << endl;
        return;
    }
    if(len == position) {
        int count = 1;
        Node* prev = head;
        while(count < position-1) {
            prev = prev -> next;
            count++;
        }
        Node* temp = tail;
        prev -> next = NULL;
        tail = prev;
        delete temp;
        return;
    }
    int count = 1;
    Node* prev = head;
    while(count < position-1) {
        prev = prev -> next;
        count++;
    }
    Node* curr = prev -> next;
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
    return;
}
void PrintLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    Node* head = new Node(10);
    Node* tail = head;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtTail(tail, 70);
    PrintLL(head);
    cout << endl;
    insertAtPosition(6, head, tail, 100);
    PrintLL(head);
    deleteNode(2, head, tail);
    PrintLL(head);
}   