#include<iostream>
using namespace std;

// Creation of Class
class Animal {
    // State or Properties
    // Access modifier
    private:
    int weight;
    public:
    int age;
    string name;

    // Behaviour or functions
    void eat () {
        cout << "I am eating";
    }
    void sleep() {
        cout << "I am sleeping";
    }

    // Getter and Setter for private states
    // Setter
    void setWeight(int weight) {
        this -> weight = weight;
    }
    // Getter
    void getWeight() {
        cout << weight;
    }
};
int main() {
    // Object Creation
    Animal lion;
    // Accessing properties of object
    lion.age = 12;
    lion.name = "Abhishek";
    cout << lion.age << " " << lion.name << endl;

    // Calling member function
    lion.eat();
    cout << endl;

    // Getter and Setter use
    lion.setWeight(300);
    cout << "Weight of lion is: ";
    lion.getWeight();
    cout << endl;

    // Dynamic Memory Allocation 
    Animal* dog = new Animal;
    dog -> name = "Aman";
    dog -> age = 11;
    cout << dog -> age << " " << dog -> name << endl;

    dog->setWeight(60);
    cout << "Weight of dog is: ";
    dog->getWeight();
    return 0;
}