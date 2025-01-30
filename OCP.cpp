// Classes should be open for extension but closed for modification.
#include <iostream>
using namespace std;

class Shape
{
    public : 
        virtual double area()  = 0;
};

class Square : public Shape{
    double width, height;
    public : 
        Square(double w,double h) : width(w) , height(h)
        {}
        double area()
        {
            return width * height;
        }
        
};

class Circle : public Shape{
    double radius;
    public : 
        Circle(double radius) : radius(radius)
        {

        }
        double area()
        {
            return 3.14*radius*radius;
        }
};

int main()
{
    Square * s1 = new Square(3,4);
    Circle * c1 = new Circle(5);

    s1->area();
    c1->area();

    delete s1;
    delete c1;

}