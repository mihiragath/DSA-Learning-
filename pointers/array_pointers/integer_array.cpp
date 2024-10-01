#include<iostream>
using namespace std;

int main () {

    // Example of array and pointer manipulation

    // Integer array of size 10, partially initialized
    // int arr[10] = {23, 122, 41, 67};

    /*
    // Prints the address of the first element
    cout <<"Address of first memory block is " << arr << endl;

    // Prints the first element (23)
    cout << arr[0] << endl;

    // Prints the address of the first element using &arr[0]
    cout <<"Address of first memory block is " << &arr[0] << endl;

    // Dereferences the pointer to print the first element (23)
    cout << "4th " << *arr << endl;

    // Adds 1 to the first element's value (23 + 1 = 24)
    cout << "5th " << *arr + 1 << endl;

    // Dereferences the pointer to the second element (122)
    cout << "6th " << *(arr + 1) << endl;

    // Adds 1 to the first element, then dereferences (23 + 1 = 24)
    cout << "7th " << *(arr) + 1 << endl;

    // Accesses the third element (41) using array index
    cout << "8th " << arr[2] << endl;

    // Accesses the third element (41) using pointer arithmetic
    cout << "9th " << *(arr+2) << endl;

    // Accesses the 4th element using reverse index notation
    int i = 3;
    cout << i[arr] << endl;  // Equivalent to arr[i]

    // Demonstrating sizeof with arrays and pointers
    int temp[10] = {1, 2};
    cout << sizeof(temp) << endl;           // Size of entire array (10 * sizeof(int))
    cout << "1st " << sizeof(*temp) << endl;  // Size of first element (sizeof(int))
    cout << "2nd " << sizeof(&temp) << endl;  // Size of pointer to array (depends on system architecture)

    // Pointer to the first element of temp
    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl;   // Size of pointer (depends on system architecture)
    cout << sizeof(*ptr) << endl;  // Size of dereferenced pointer (sizeof(int))
    cout << sizeof(&ptr) << endl;  // Size of pointer to pointer

    // Another example with arrays
    int a[20] = {1, 2, 3, 5};
    int *p = &a[0];
    cout << "-> " << &p << endl;  // Prints address of pointer `p`
    */

    // Working with pointers and arrays
    int arr[10];

    // ERROR: Arrays cannot be reassigned to another address
    // arr = arr + 1;  // This is not allowed since arrays are non-modifiable lvalues

    // Pointer manipulation
    int *ptr = &arr[0];
    cout << ptr << endl;  // Prints the address of the first element of arr
    ptr = ptr + 1;        // Moves the pointer to the next element
    cout << ptr << endl;  // Prints the new address (one int forward in memory)

    return  0;
}
