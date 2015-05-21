// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa227 - Puzzle
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=163
 *
 * Time  : O(m), m is number of moves
 * Space : O(1)
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::ostream_iterator;
using std::prev;
using std::copy;
using std::swap;
using std::move;

void PrintPuzzle(const vector<string>& puzzle) {
    // Formatted output.
    for (int i = 0; i < puzzle.size(); ++i) {
        ostream_iterator<char> out_it(cout, " ");
        copy(puzzle[i].begin(), prev(puzzle[i].end()), out_it);
        cout << *prev(puzzle[i].end()) << endl;
    }
}

void MovePuzzle(const string& moves, vector<string>* puzzle) {
    // Define each direction.
    unordered_map<char, pair<int, int>> direction{{'A', {-1, 0}},
                                                  {'B', {1, 0}},
                                                  {'R', {0, 1}},
                                                  {'L', {0, -1}},
                                                  {'0', {0, 0}}};
    // Find empty square.
    int i = 0, j = 0;
    for (; i < puzzle->size(); ++i) {
        if ((j = (*puzzle)[i].find(' ')) != string::npos) {
            break;
        }
    }
    // Move by the step and check if it is valid or not.
    for (const char& c : moves) {
        int new_i = i + direction[c].first, new_j = j + direction[c].second;
        if (new_i < 0 || new_i >= puzzle->size() ||
            new_j < 0 || new_j >= (*puzzle)[i].length()) {
                cout << "This puzzle has no final configuration." << endl;
                return;
        } else {
            swap((*puzzle)[i][j], (*puzzle)[new_i][new_j]);
            i = new_i;
            j = new_j;
        }
    }

    PrintPuzzle(*puzzle);
}

int main() {
    int T = 0;
    vector<string> puzzle(5, "");

    while (getline(cin, puzzle[0]) && puzzle[0] != "Z") {
        for (int i = 1; i < 5; ++i) {
            getline(cin, puzzle[i]);
        }

        string moves, tmp;
        while (getline(cin, tmp) && tmp.back() != '0') {
            moves.append(tmp);
        }
        moves.append(tmp);

        if (++T > 1) {
            cout << endl;
        }
        cout << "Puzzle #" << T << ":" << endl;
        MovePuzzle(moves, &puzzle);
    }

    return 0;
}
