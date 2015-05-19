// UVa202 - Repeating Decimals
// Time:  O(d), d is size of the denominator
// Space: O(d)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    const int limit = 50;
    int a, b;
    
    while (cin >> a >> b) {
        unordered_map<int, int> remainder_index;
        vector<int> decimal_digits;
        int index = 0;
        int result = a / b;
        int remainder = a % b;
        while (!remainder_index.count(remainder)) {
            remainder_index[remainder] = index++;
            result = remainder * 10 / b;
            decimal_digits.emplace_back(result);
            remainder = (remainder * 10) % b;
        }
        
        // Print out the integer.
        cout <<  a << "/" << b << " = " << a / b << ".";
        
        // Print out the decimals.
        int cycle_start_index = remainder_index[remainder], n_cur_digit = 0;
        for (; n_cur_digit < cycle_start_index && n_cur_digit < limit; ++n_cur_digit) {
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
        
        cout << "   " << index - cycle_start_index
             << " = number of digits in repeating cycle" << endl << endl;
    }
    
    return 0;
}