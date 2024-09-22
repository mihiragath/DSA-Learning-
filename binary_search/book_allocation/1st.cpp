#include <iostream>
using namespace std;

// Helper function to check if the allocation is possible with the current mid value
bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;  // Number of students required
    int pageSum = 0;       // Sum of pages allocated to the current student

    // Traverse through each book
    for (int i = 0; i < n; i++) {
        if (pageSum + arr[i] <= mid) {
            // Allocate the current book to the current student
            pageSum += arr[i];
        } else {
            // Allocate to the next student
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                // If the number of students exceeds the limit or a book has more pages than mid, return false
                return false;
            }
            pageSum = arr[i];  // Reset the page sum for the new student
        }
    }
    return true;
}

// Main function to find the minimum possible maximum number of pages to allocate
int allocateBook(int arr[], int n, int m) {
    int s = 0;   // Start of binary search range
    int sum = 0; // Sum of all pages

    // Calculate the total sum of pages
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int e = sum;             // End of binary search range
    int ans = -1;            // To store the answer (minimum of the maximum allocation)
    int mid = s + (e - s) / 2;  // Calculate mid value

    // Binary search to find the optimal allocation
    while (s <= e) {
        if (isPossible(arr, n, m, mid)) {
            // If the current mid value is a possible solution, store the result
            ans = mid;
            e = mid - 1;  // Try to find a better (smaller) solution
        } else {
            s = mid + 1;  // Increase the value of mid to find a feasible solution
        }
        mid = s + (e - s) / 2;  // Recalculate mid value
    }

    return ans;  // Return the minimum possible maximum number of pages
}

int main() {
    int arr[] = {12, 34, 67, 90}; // Example: pages in each book
    int n = 4;                    // Number of books
    int m = 2;                    // Number of students

    cout << "Minimum possible maximum pages: " << allocateBook(arr, n, m) << endl;

    return 0;
}
