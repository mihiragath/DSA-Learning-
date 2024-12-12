#include <iostream>
using namespace std;

// Structure to store petrol and distance for each petrol pump
struct petrolPump
{
    int petrol;   // Amount of petrol available at the pump
    int distance; // Distance to the next petrol pump
};

// Function to find the starting point where the truck can complete the circle
int findStartingPoint(petrolPump p[], int n)
{
    int deficit = 0; // Keeps track of the petrol deficit
    int balance = 0; // Tracks the current petrol balance
    int start = 0;   // Stores the starting point index

    // Traverse through all petrol pumps
    for (int i = 0; i < n; i++)
    {
        // Calculate balance at the current pump
        balance += p[i].petrol - p[i].distance;

        // If balance goes negative, the current start is not valid
        if (balance < 0)
        {
            // Move starting point to the next pump
            start = i + 1;

            // Add the negative balance to deficit
            deficit += balance;

            // Reset balance to 0 for the new start
            balance = 0;
        }
    }

    // If the total balance (balance + deficit) is non-negative,
    // the journey is possible from the start point
    return (balance + deficit >= 0) ? start : -1;
}

int main()
{
    int t; // Number of test cases
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--)
    {
        int n; // Number of petrol pumps
        cout << "Enter number of petrol pumps: ";
        cin >> n;

        petrolPump p[n]; // Array to store petrol and distance for each pump
        cout << "Enter petrol and distance for each pump:\n";

        // Input petrol and distance values for each pump
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].petrol >> p[i].distance;
        }

        // Find the starting point
        int result = findStartingPoint(p, n);

        // Output the result
        if (result != -1)
        {
            cout << "Start at petrol pump index: " << result << endl;
        }
        else
        {
            cout << "No possible starting point.\n";
        }
    }

    return 0;
}
