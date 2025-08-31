#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printDoublyLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(tail == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }
    int len = getLength(head);
    if(position == len) {
        insertAtTail(head, tail, data);
        return;
    }
    int count = 1;
    Node* prevNode = head;
    while(count < position-1) {
        prevNode = prevNode -> next;
        count++;
    }
    Node* curr = prevNode -> next;
    Node* newNode = new Node(data);
    newNode -> next = curr;
    curr -> prev = newNode;
    prevNode -> next = newNode;
    newNode -> prev = prevNode;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    if(head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }
    if(head -> next == NULL) {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return; 
    }
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);
    if(position > len || position <= 0) {
        cout << "Invalid No deletion" << endl;
        return;
    }
    if(position == len) {
        Node* temp = tail;
        tail = tail -> prev;
        temp -> prev = NULL;
        tail -> next = NULL;
        delete temp;
        return;
    }
    int count = 1;
    Node* left = head;
    while(count < position-1) {
        left = left -> next;
        count++;
    }
    Node* curr = left -> next;
    Node* right = curr -> next;
    left -> next = right;
    right -> prev = left;
    curr -> next = NULL;
    curr -> prev = NULL;
    delete curr;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    printDoublyLL(head);
    cout << endl;
    insertAtPosition(head, tail, 4, 100);
    printDoublyLL(head);
    cout << endl;
    deleteNode(head, tail, 6);
    printDoublyLL(head);
}
