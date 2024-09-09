#include <iostream>
#include <vector>
using namespace std;

// Function to swap two arrays
void swapArrays(vector<int>& arr1, vector<int>& arr2) {
    if (arr1.size() != arr2.size()) {
        cout << "Arrays must be of the same size to swap." << endl;
        return;
    }
    
    for (int i = 0; i < arr1.size(); i++) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
    // using swap function
    /* for (int i = 0; i < arr1.size(); i++) {
        swap(arr1[i], arr2[i]);  // Swap elements using the built-in swap function
    }*/
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {6, 7, 8, 9, 10};

    cout << "Original Arrays:" << endl;
    cout << "Array 1: ";
    printArray(array1);
    cout << "Array 2: ";
    printArray(array2);

    // Swap the arrays
    swapArrays(array1, array2);

    cout << "\nArrays after swapping:" << endl;
    cout << "Array 1: ";
    printArray(array1);
    cout << "Array 2: ";
    printArray(array2);

    return 0;
}
