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

Node* getMiddle(Node* &head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    Node* fast = head;  
    Node* slow = head;
    while(slow != NULL && fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return slow;
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

    cout << "Middle node in the Linked List is: " << getMiddle(head)->data << endl;
    return 0;
}