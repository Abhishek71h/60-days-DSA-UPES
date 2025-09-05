#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};
Node* sortLL(Node* &head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* curr = head;
    while(curr != NULL) {
        if(curr -> data == 0) {
            zeroCount++;
        }
        if(curr -> data == 1) {
            oneCount++;
        }
        if(curr -> data == 2) {
            twoCount++;
        }
        curr = curr -> next;
    }
    curr = head;
    while(zeroCount--) {
        curr -> data = 0;
        curr = curr -> next;
    }
    while(oneCount--) {
        curr -> data = 1;
        curr = curr -> next;
    }
    while(twoCount--) {
        curr -> data = 2;
        curr = curr -> next;
    }
    return head;
}
void printLL(Node* &head) {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr -> data << " ";
        curr = curr -> next;
    }
}
int main() {
    Node* head = new Node(1);
    Node* second = new Node(0);
    Node* third = new Node(1);
    Node* fourth = new Node(2);
    Node* fifth = new Node(0);
    Node* sixth = new Node(2);
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = NULL;
    sortLL(head);
    printLL(head);
}