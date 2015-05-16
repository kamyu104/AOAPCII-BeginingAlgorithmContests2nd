// UVa11809 Floating-Point Numbers

#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;

int main() {
    double M[10][31];
    long long int E[10][31];
    
    // Build up the mapping table from "a * 2^b" to "c * 10^d"
    for (int i = 0; i <= 9; ++i) {
        for (int j = 1; j <= 30; ++j) {
            int a = 1 - pow(2, -(i + 1)); // max mantissa = 1 - 2^(-i-1)
            int b = pow(2, j) - 1;        // max exponent = 2^j - 1
            
            // a * 2^b = c * 10^d => log10(a) + b * log10(2) = log10(c) + d
            // Let x = log10(a) + b * log10(2), d = floor(), then c = 10^(x-d)
            int x = log10(a) + b * log10(2);
            int d = floor(x);
            int c = pow(10, x - d);
            M[i][j] = c;
            E[i][j] = d;
        }
    }
    
    string s;
    while (cin >> s && s != "0e0") {
        s[17] = ' '; // Replace 'e' with ' '.
        stringstream ss(s);
        double p;
        int q;
        ss >> p >> q;
        // Lookup the mapping table from "c * 10^d" to "a * 2^b"
        for (int i = 0; i < 10; ++i) {
            for (int j = 1; j <= 30; ++j) {
                if (fabs(M[i][j] - p) < 1e-4 && E[i][j] == q) {
                    cout << i << ' ' << j << endl;
                }
            }
        }
    }
    return 0;
}