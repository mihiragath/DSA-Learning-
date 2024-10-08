#include<iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    // Constructor with default arguments
    Rectangle(int l = 1, int w = 1) {
        length = l;
        width = w;
    }

    // Function to calculate area
    int area() {
        return length * width;
    }

    // Function to calculate perimeter
    int perimeter() {
        return 2 * (length + width);
    }

    // Function to display dimensions
    void displayDimensions() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    // Creating a rectangle with default dimensions
    Rectangle rect1;
    cout << "Rectangle 1:" << endl;
    rect1.displayDimensions();
    cout << "Area: " << rect1.area() << endl;
    cout << "Perimeter: " << rect1.perimeter() << endl;

    cout << endl;

    // Creating a rectangle with provided dimensions
    Rectangle rect2(4, 5);
    cout << "Rectangle 2:" << endl;
    rect2.displayDimensions();
    cout << "Area: " << rect2.area() << endl;
    cout << "Perimeter: " << rect2.perimeter() << endl;

    cout << endl;

    // Creating a rectangle with only length provided (width uses default value)
    Rectangle rect3(7);
    cout << "Rectangle 3:" << endl;
    rect3.displayDimensions();
    cout << "Area: " << rect3.area() << endl;
    cout << "Perimeter: " << rect3.perimeter() << endl;

    return 0;
}
