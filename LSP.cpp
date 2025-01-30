// Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.

#include <iostream>
using namespace std;

class Bird
{
public:
    virtual void makeSound() { cout << "Bird is chirping!" << endl; }
};

class IFlyable
{
public:
    virtual void fly() = 0; // Pure virtual function
};

class Sparrow : public Bird, public IFlyable
{
public:
    void fly() override { cout << "Sparrow is flying!" << endl; }
};

class Penguin : public Bird
{
public:
    void makeSound() override { cout << "Penguin is honking!" << endl; }
};

int main()
{
    Sparrow sparrow;
    Penguin penguin;

    sparrow.makeSound();
    sparrow.fly(); // ✅ Only birds that can fly have a fly() method

    penguin.makeSound();
    // penguin.fly(); ❌ Error: Penguins are not IFlyable, maintaining LSP

    return 0;
}
