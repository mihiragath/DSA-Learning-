#include<iostream> 
using namespace std;

// Defining a constant for PI using macro
#define PI 3.14

int main() {

    int r = 5;  // Radius of the circle

    // Calculating the area of the circle using the formula: area = PI * r^2
    double area = PI * r * r;

    // Output the calculated area
    cout << "Area is " << area << endl;

    return 0;
}
    