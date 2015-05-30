// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa202 - Repeating Decimals
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=138
 *
 * Time  : O(d), d is size of the denominator
 * Space : O(d)
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::min;

int main() {
    const int limit = 50;
    int a, b;

    while (cin >> a >> b) {
        unordered_map<int, int> remainder_index;
        vector<int> decimal_digits;

        // Count the decimals part.
        int index = 0;
        int result = a / b;
        int remainder = a % b;
        while (!remainder_index.count(remainder)) {
            remainder_index[remainder] = index++;
            result = remainder * 10 / b;
            decimal_digits.emplace_back(result);
            remainder = (remainder * 10) % b;
        }

        // Print out the integer part.
        cout <<  a << "/" << b << " = " << a / b << ".";

        // Print out the decimals.
        int cycle_start_index = remainder_index[remainder], n_cur_digit = 0;
        for (; n_cur_digit < min(cycle_start_index, limit); ++n_cur_digit) {
            cout << decimal_digits[n_cur_digit];
        }

        // Print out repeating part of the decimals.
        cout << "(";
        for (; n_cur_digit < min(index, limit); ++n_cur_digit) {
            cout << decimal_digits[n_cur_digit];
        }
        if (index >= limit) {
            cout << "...";
        }
        cout << ")" << endl;

        // Print out number of digits in repeating cycle.
        cout << "   " << index - cycle_start_index
             << " = number of digits in repeating cycle" << endl << endl;
    }

    return 0;
}
