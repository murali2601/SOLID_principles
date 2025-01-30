// A class should have only one reason to change, meaning it should have only one responsibility.
#include <iostream>
using namespace std;

class display
{
    public : 
        void display_msg(int sum) const
        {
            cout << "Total SUM : "  << sum << endl;
        }
};

class calculate
{
    public : 
        void calculate_value(int a,int b, int *sum)
        {
            *sum = a+b;
        }
};

int main()
{
    int sum = 0;

    display * d1 = new display();
    calculate * c1 = new calculate();
    c1->calculate_value(2,3,&sum);
    d1->display_msg(sum);

    delete d1;
    delete c1;

}