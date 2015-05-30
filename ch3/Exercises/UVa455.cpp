// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa455 - Periodic Strings
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=396
 *
 * Time  : O(n * f), n is length of the string, f is number of factors of n.
 * Space : O(1)
 *
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void FindMinPeriod(const string& periodic_str) {
    for (int len = 1; len <= periodic_str.length(); ++len) {
        // len is a factor of the length.
        if (periodic_str.length() % len == 0) {
            string str = periodic_str.substr(0, len);
            int i = len;
            for (; i < periodic_str.length(); i += len) {
                // periodic_str is not repetitions of str.
                if (str != periodic_str.substr(i, len)) {
                    break;
                }
            }
            // periodic_str is repetitions of str.
            if (i == periodic_str.length()) {
                cout << len << endl;
                return;
            }
        }
    }
}

int main() {
    int i = 0;
    int T;
    cin >> T;

    while (i < T) {
        string periodic_str;
        cin >> periodic_str;

        if (++i > 1) {
            cout << endl;
        }

        FindMinPeriod(periodic_str);
    }
    return 0;
}
