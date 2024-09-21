#include <iostream>
using namespace std;

// Function to perform binary search to find the integer square root of a number
 int squareNum(int num) {
     int s = 0;                  // Start of the search range
     int e = num;                // End of the search range
     int mid = s + (e - s) / 2;  // Calculate mid-point of current range
     int ans = -1;               // Variable to store the answer
    
    // Binary search loop to find the integer square root
    while (s <= e) {
         int square = mid * mid; // Calculate the square of mid
        
        // If the square of mid is exactly equal to the number
        if (square == num) {
            return mid;         // Return mid as the integer square root
        }

        // If the square of mid is less than the number
        if (square < num) {
            ans = mid;          // Store mid as the potential answer
            s = mid + 1;        // Move the start to mid + 1 to search the right half
        }
        // If the square of mid is greater than the number
        else {
            e = mid - 1;        // Move the end to mid - 1 to search the left half
        }

        // Recalculate mid after adjusting start or end
        mid = s + (e - s) / 2;
    }
    
    return ans;  // Return the closest integer square root if an exact match isn't found
}

// Function to refine the integer square root to a specified precision
double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;          // Factor used to add precision in each iteration
    double ans = tempSol;       // Start with the integer square root (tempSol)
    
    // Loop to add precision step by step
    for (int i = 0; i < precision; i++) {
        factor = factor / 10;   // Reduce the factor by 10 in each precision step

        // Loop to find the next more precise value for the square root
        for (double j = ans; j * j < n; j = j + factor) {
            ans = j;            // Update ans to the most precise value found
        }
    }

    return ans;  // Return the square root with added precision
}

int main() {
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    // Call binarySearch to find the integer square root (without decimals)
    int tempSol = squareNum(n);

    // Call morePrecision to add precision to the integer square root
    cout << "Answer is: " << morePrecision(n, 3, tempSol) << endl;  // Precision up to 3 decimal places
    cout<< "squareroot of the number is:" <<squareNum(n)<<endl;
    return 0;
}
