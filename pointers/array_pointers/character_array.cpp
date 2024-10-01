#include<iostream>
using namespace std;

int main() {

    // Integer array
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Character array (C-string) with null terminator
    char ch[6] = "abcde";

    // Prints memory address of the first element of `arr`
    cout << arr << endl;

    // Prints the string stored in `ch`
    cout << ch << endl;

    // Pointer to the first element of `ch`
    char *c = &ch[0];

    // Prints the string starting at `c`
    cout << c << endl;

    // Single character 'z'
    char temp = 'z';

    // Pointer to `temp`
    char *p = &temp;

    // Prints 'z' followed by garbage (no null terminator)
    cout << p << endl;

    return 0;
}
