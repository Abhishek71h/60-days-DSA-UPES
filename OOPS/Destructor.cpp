#include<iostream>
using namespace std;
class Animal {
    public:
    int age;

    ~Animal() {
        cout << "Destructor called" << endl;
    }
};
int main() {
    Animal lion; // Static allocation -> Automatically calls the destructor

    Animal* dog = new Animal; // Dynamic allecoation -> Manually calls the destructor
    delete dog;
}