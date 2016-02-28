// Copyright (c) 2016 kamyu. All rights reserved.

/*
 * UVa201 Squares
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=137
 *
 * Time  : O(n^4)
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
    const int MAX_N = 9;  // 2 <= n <= 9
    int n, m, x, y, T = 0;
    char c;
    while (cin >> n >> m) {
        vector<vector<bool>> H(MAX_N + 1, vector<bool>(MAX_N + 1));
        vector<vector<bool>> V(MAX_N + 1, vector<bool>(MAX_N + 1));
        for (int i = 1 ; i <= m; ++i) {
            cin >> c >> x >> y;
            if (c == 'H') {
                H[x][y] = true;
            } else {
                V[y][x] = true;
            }
        }
        if (T++) {
            cout << endl
                 << "**********************************"
                 << endl
                 << endl;
        }
        cout << "Problem #" << T << endl << endl;

        int sum = 0;
        for (int l = 1 ; l <= n; ++l) {
            int count = 0;
            for (int i = 1; i + l <= n; ++i) {
                for (int j = 1; j + l <= n; ++j) {
                    bool flag = true;
                    for (int h = j; h < j + l && flag; ++h) {
                        flag = (H[i][h] && H[i + l][h]);
                    }
                    for (int v = i ; v < i + l && flag; ++v) {
                        flag = (V[v][j] && V[v][j + l]);
                    }
                    count += flag ? 1 : 0;
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
