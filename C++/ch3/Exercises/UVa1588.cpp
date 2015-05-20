// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa1588 - Kickdown
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4463
 *
 * Time  : O(m * n)
 * Space : O(1)
 *
 */

#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;
using std::min;


bool IsValid(const int k, const string& s1, const string& s2) {
    for (int i = 0; k + i < s1.length() && i < s2.length(); ++i) {
        if ((s1[k + i] - '0') + (s2[i] - '0') > 3) {
            return false;
        }
    }
    return true;
}

size_t Cut(const string& s1, const string& s2) {
    int k = 0;
    while (!IsValid(k, s1, s2)) {
        ++k;
    }
    return max(s1.length(), s2.length() + k);
}

int main() {
    string bottom, top;
    while (cin >> bottom >> top) {
        cout << min(Cut(bottom, top), Cut(top, bottom)) << endl;
    }
    return 0;
}
