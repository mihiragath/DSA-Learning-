#include<iostream>
using namespace std;

void print(int *p) {
    // Prints the value pointed to by `p`
    cout << *p << endl; 
}

void update(int *p) {
    // Uncommenting p = p + 1 changes the pointer itself, but here we update the value
    *p = *p + 1;  // Increment the value at the pointer
}

// When passing an array to a function, it decays to a pointer, so *arr and arr[] are treated the same
int getSum(int *arr, int n) {
    // Prints the size of the pointer, not the array
    cout << endl << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    // Summing the array elements
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
/*
    int value = 5;
    int *p = &value;

    // Uncomment to print and update value
    // print(p);
    cout <<" Before " << *p << endl;
    update(p);
    cout <<" After " << *p << endl;
*/

    // Initialize array
    int arr[6] = {1, 2, 3, 4, 5, 8};

    // Pass a sub-array starting at `arr+3` (i.e., {4, 5, 8}) to `getSum`
    cout << "Sum is " << getSum(arr + 3, 3) << endl ;  

    return 0;
}
