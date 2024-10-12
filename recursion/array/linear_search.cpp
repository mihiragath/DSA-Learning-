#include <iostream> 

using namespace std; 

bool linearSearch(int *arr, int size, int key){
    // Base case: If size is 0, return false
    if(size == 0){
        return false;
    }

    // If the first element matches the key, return true
    if(arr[0] == key){
        return true;
    }

    // Otherwise, search in the remaining array
    bool linear = linearSearch(arr + 1, size - 1, key);
    return linear;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int key = 3;

    // Call linear search
    bool ans = linearSearch(arr, size, key);

    // Print result
    if(ans){
        cout << "present" << endl;
    }
    else{
        cout << "absent" << endl;
    }

    return 0;
}
