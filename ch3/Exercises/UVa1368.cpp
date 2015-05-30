// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa1368 - DNA Consensus String
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4114
 *
 * Time  : O(m * n)
 * Space : O(1)
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

void ConsensusString(const vector<string>& DNAs,
                     string* consensus_string,
                     int* error_count) {
    for (int j = 0; j < DNAs[0].length(); ++j) {
        // Count.
        unordered_map<char, int> count;
        for (int i = 0; i < DNAs.size(); ++i) {
            ++count[DNAs[i][j]];
        }

        // Find smallest consensus nucleotide.
        char consensus = 'A';
        // Be aware of the order.
        for (const auto& nucleotide : {'A', 'C', 'G', 'T'}) {
            if (count[nucleotide] > count[consensus]) {
                consensus = nucleotide;
            }
        }

        // Update info.
        (*consensus_string)[j] = consensus;
        *error_count += DNAs.size() - count[consensus];
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;

        vector<string> DNAs(m);
        for (int i = 0; i < DNAs.size(); ++i) {
            cin >> DNAs[i];
        }

        string consensus_string(n, 'A');
        int error_count = 0;
        ConsensusString(DNAs, &consensus_string, &error_count);

        cout << consensus_string << endl;
        cout << error_count << endl;
    }

    return 0;
}
