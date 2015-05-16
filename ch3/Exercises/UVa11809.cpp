// UVa11809 Floating-Point Numbers
#include <iostream>
#include <cmath>
#include <sstream>
#include <unordered_map>
#include <tuple>
using namespace std;

struct HashPair {
    size_t operator()(const pair<double, int>& p) const {
        return hash<double>()(p.first) ^ hash<int>()(p.second);
    }
};

int main() {
    unordered_map<pair<double, int>, pair<int,int>, HashPair> map;
    // Build up the mapping table from "a * 2^b" to "c * 10^d"
    for (int i = 0; i <= 9; ++i) {
        for (int j = 1; j <= 30; ++j) {
            double a = 1 - pow(2, -(i + 1)); // max mantissa = 1 - 2^(-i-1)
            int b = pow(2, j) - 1;        // max exponent = 2^j - 1
            
            // a * 2^b = c * 10^d => log10(a) + b * log10(2) = log10(c) + d
            // Let d = floor(log10(a) + b * log10(2)), then c = 10^(x-d)
            double x = log10(a) + b * log10(2);
            int d = floor(x);
            double c = pow(10, x - d);
            map[make_pair(c, d)] = make_pair(i, j);
        }
    }
    
    string s;
    while (cin >> s && s != "0e0") {
        s[17] = ' '; // Replace 'e' with ' '.
        
        stringstream ss(s);
        double p;
        int q;
        ss >> p >> q;
        // Lookup the mapping table from "c * 10^d" to
        for (const auto& pv : map) {
            pair<double, int> key;
            pair<int, int> val;
            tie(key, val) = pv;
            if (fabs(key.first - p) < 1e-4 && key.second == q) {
                cout << val.first << ' ' << val.second << endl;
            }
        }
    }
    return 0;
}