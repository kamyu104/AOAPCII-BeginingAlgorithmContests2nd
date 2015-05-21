// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa10340 - All in All
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1281
 *
 * Time  : O(m), m is length of t.
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
    string s, t;
    while (cin >> s >> t) {
        int i, j;
        for (i = 0, j = 0; i < t.length() && j < s.length(); ++i) {
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
