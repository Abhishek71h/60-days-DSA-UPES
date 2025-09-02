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

Node* removeLoopinLL(Node* &head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        Node* fast = head;
        Node* slow = head;
        bool hasCycle = false;
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle) {
            cout << "Linked List has not cycle";
            return head;
        }
        slow = head;
        if(slow == fast) {
            while(fast -> next != slow) {
                fast = fast -> next;
            }
            fast -> next = NULL;
            return head;
        }
        Node* prev = NULL;
        while(fast != slow) {
            prev = fast;
            fast = fast -> next;
            slow = slow -> next;
        }
        prev -> next = NULL;
        return head;
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
    sixth -> next = head;
    cout << endl;
    removeLoopinLL(head);
    PrintLL(head);
    return 0;
}