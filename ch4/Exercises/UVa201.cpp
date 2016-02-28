// Copyright (c) 2016 kamyu. All rights reserved.

/*
 * UVa201 Squares
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=137
 *
 * Time  : O(n^3)
 * Space : O(n^2)
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int n, m, x, y, T = 0;
    char c;
    while (cin >> n >> m) {
        vector<vector<bool>> H(n, vector<bool>(n));
        vector<vector<bool>> V(n, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            cin >> c >> x >> y;
            if (c == 'H') {
                H[x - 1][y - 1] = true;
            } else {
                V[y - 1][x - 1] = true;
            }
        }
        if (T++) {
            cout << endl
                 << "**********************************"
                 << endl
                 << endl;
        }
        cout << "Problem #" << T << endl << endl;

        vector<vector<int>> H_len(n, vector<int>(n));
        vector<vector<int>> V_len(n, vector<int>(n));
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (V[i][j]) {
                    V_len[i][j] = V_len[i + 1][j] + 1;
                }
                if (H[j][i]) {
                    H_len[j][i] = H_len[j][i + 1] + 1;
                }
            }
        }

        int sum = 0;
        for (int l = 1; l <= n; ++l) {
            int count = 0;
            for (int i = 0; i + l < n; ++i) {
                for (int j = 0; j + l < n; ++j) {
                    if (V_len[i][j] >= l &&  V_len[i][j + l] >= l &&
                        H_len[i][j] >= l &&  H_len[i + l][j] >= l) {
                        ++count;
                    }
                }
            }
            sum += count;
            if (count) {
                cout << count << " square (s) of size " << l << endl;
            }
        }

        if (!sum) {
            cout << "No completed squares can be found." << endl;
        }
    }
    return 0;
}
