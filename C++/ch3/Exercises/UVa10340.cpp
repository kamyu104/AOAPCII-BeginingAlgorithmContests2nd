// UVa10340 - All in All
// Time:  O(m), m is length of t.
// Space: O(1)

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int i, j;
        for (i = 0, j = 0 ; i < t.length() && j < s.length() ; ++i ) {
            if (t[i] == s[j]) {
                ++j;
            }
        }
        
        if (j == s.length()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}