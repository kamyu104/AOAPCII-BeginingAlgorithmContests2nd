// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa1585 - Score
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4460
 *
 * Time  : O(n)
 * Space : O(1)
 *
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
