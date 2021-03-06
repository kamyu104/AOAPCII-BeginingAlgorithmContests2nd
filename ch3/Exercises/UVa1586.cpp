// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa1586 - Molar Mass
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4461
 *
 * Time  : O(n)
 * Space : O(1)
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ios;

double AtomicWeightOf(const char atom) {
    switch (atom) {
        case 'C':
            return 12.01;
            break;
        case 'H':
            return 1.008;
            break;
        case 'O':
            return 16.00;
            break;
        default:
            return 14.01;
            break;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string formula;
        cin >> formula;

        double result = 0;
        int i = 0;
        while (i < formula.length()) {
            // Parse the number of the atom.
            string temp_str = "0";
            int temp_index = i + 1;
            while (temp_index < formula.length() &&
                   isdigit(formula[temp_index])) {
                temp_str.append(1, formula[temp_index]);
                ++temp_index;
            }

            double multiplier = atof(temp_str.c_str());
            if (multiplier == 0.0) {
                multiplier = 1.0;
            }
            result += multiplier * AtomicWeightOf(formula[i]);

            i = temp_index;
        }
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(3);
        cout << result << endl;
    }
    return 0;
}
