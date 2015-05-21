// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa1225 - Digit Counting
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=3666
 *
 * Time  : O(logn)
 * Space : O(1)
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream_iterator;
using std::prev;
using std::copy;

void PrintDigitCounts(const vector<int>& digit_counts) {
    // Formatted output.
    ostream_iterator<int> out_it(cout, " ");
    copy(digit_counts.begin(), prev(digit_counts.end()), out_it);
    cout << *prev(digit_counts.end()) << endl;
}

void DigitCounting(const int n) {
    vector<int> digit_counts(10, 0);

    for (int k = 0; k <= 9; ++k) {
        int cnt = 0, multiplier = 1, left_part = n;
        while (left_part > 0) {
            // split number into: left_part, curr, right_part
            int curr = left_part % 10;
            int right_part = n % multiplier;

            // count of (c000 ~ oooc000) = (ooo + (k < curr)? 1 : 0) * 1000
            cnt += (left_part / 10 + (k < curr)) * multiplier;

            // if k == 0, oooc000 = = (ooo - 1) * 1000
            if (k == 0 && multiplier > 1) {
                cnt -= multiplier;
            }

            // count of (oook000 ~ oookxxx): count += xxx + 1
            if (curr == k) {
                cnt += right_part + 1;
            }

            left_part /= 10;
            multiplier *= 10;
        }

        digit_counts[k] = k == 0 ? cnt - 1 : cnt;
    }

    PrintDigitCounts(digit_counts);
}

int main() {
    int T = 0;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        DigitCounting(n);
    }
    return 0;
}
