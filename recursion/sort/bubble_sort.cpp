#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size) {
    if(size == 0 || size == 1) {
        return; // base case, already sorted
    }

    // Perform one pass of bubble sort
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursively call bubble sort on the remaining unsorted part
    bubbleSort(arr, size - 1);
}

int main() {
    int arr[7] = {1, 5, 4, 3, 2, 6, 7};
    
    // Call bubbleSort on the array
    bubbleSort(arr, 7);

    // Output the sorted array
    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
