// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa11809 Floating-Point Numbers
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=2909

 *
 * Time  : O(M * E) for building map, O(1) per test case
 * Space : O(M * E) for map
 *
 */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <tuple>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::hash;
using std::pair;
using std::make_pair;

struct HashPair {
    size_t operator()(const pair<double, int>& p) const {
        return hash<double>()(p.first) ^ hash<int>()(p.second);
    }
};

int main() {
    unordered_map<pair<double, int>, pair<int, int>, HashPair> map;
    // Build up the mapping table from "c * 10^d" to "a * 2^b".
    for (int i = 0; i <= 9; ++i) {
        for (int j = 1; j <= 30; ++j) {
            double a = 1 - pow(2, -(i + 1));  // max mantissa = 1 - 2^(-i-1)
            int b = pow(2, j) - 1;        // max exponent = 2^j - 1

            // a * 2^b = c * 10^d => log10(a) + b * log10(2) = log10(c) + d
            // Let d = floor(log10(a) + b * log10(2)), then c = 10^(x-d).
            double x = log10(a) + b * log10(2);
            int d = floor(x);
            double c = pow(10, x - d);
            map[make_pair(c, d)] = make_pair(i, j);
        }
    }

    string s;
    while (cin >> s && s != "0e0") {
        s[17] = ' ';  // Replace 'e' with ' '.

        stringstream ss(s);
        double p;
        int q;
        ss >> p >> q;
        // Lookup the mapping table from "c * 10^d" to "a * 2^b".
        for (const auto& kv : map) {
            pair<double, int> key;
            pair<int, int> val;
            tie(key, val) = kv;
            if (fabs(key.first - p) < 1e-4 && key.second == q) {
                cout << val.first << ' ' << val.second << endl;
            }
        }
    }
    return 0;
}
