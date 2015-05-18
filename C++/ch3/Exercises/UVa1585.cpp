// UVa1585 - Score
// Time:  O(n)
// Space: O(1)

#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string result;
        cin >> result;
        
        int score = 0;
        int increment = 0;
        for (const auto& c : result) {
            if (c == 'O') {
                ++increment;
                score += increment;
            } else {
                increment = 0;
            }
        }
        
        cout << score << endl;
    }
    return 0;
}