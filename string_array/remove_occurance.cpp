#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Keep removing occurrences of 'part' from 's'
        while (s.length() != 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    // Input strings
    string s = "daabcbaabcba";
    string part = "abc";
    
    // Call the removeOccurrences function and get the result
    string result = sol.removeOccurrences(s, part);
    
    // Output the result
    cout << "Original String: " << s << endl;
    cout << "Part to Remove: " << part << endl;
    cout << "Resulting String: " << result << endl;
    
    return 0;
}
