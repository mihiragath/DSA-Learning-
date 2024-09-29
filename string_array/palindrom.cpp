#include <iostream>

using namespace std;

bool checkPalindrom(char name[], int n){
    int s=0;
    int e=n-1;

    while(s<e){
        if(name[s] != name[e]){
            return 0;
        }else{
            s++;
            e--;
        }
    }
    return 1;
}

// Function to calculate the length of the string
int length(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    cout << "Hello, World!" << endl;
    
    char name[20];
    cout << "Enter your name: ";
    cin >> name; // Reading the name (a string)

    int len = length(name);
    cout << "Length of the string: " << len << endl;

    int palin = checkPalindrom(name,len);
    cout << "palindrom no is:" << palin ;


    return 0;
}
