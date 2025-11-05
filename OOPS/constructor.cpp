#include<iostream>
using namespace std;

class Animal {
    public:
    int age;
    int name;
    
    // Default Constructor
    Animal() {
        cout << "Default Constructor" << endl;
    }
    // Parameterized Constructor
    Animal(int age) {
        this -> age = age;
        cout << "Parameterized Constructor Called" << endl;
    }
    // Copy Constructor
    Animal(Animal& obj) {
        this -> age = age;
        cout << "Copy Constructor Called" << endl;
    }
};
int main() {
    // Object Creation
    Animal lion; // Default Constructor Called

    Animal Abhishek(21); // Parameterized Constructor Called

    Animal copy(lion); // Copy Constructor Called
} 