// Copyright (c) 2016 kamyu. All rights reserved.

/*
 * UVa1589 Xiangqi
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4464
 *
 * Time  : O(1)
 * Space : O(1)
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;

struct Piece{
    int r, c;
    char type;
};

// The possible moves of General.
const vector<vector<int>> dir{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

// The possible moves of Horse.
const vector<vector<int>> Hdir {
    { -1, 2, 0, 2 }, { 1, 2, 0, 2 },
    { -2, -1, -2, 0 }, { -2, 1, -2, 0 },
    { -1, -2, 0, -2 }, { 1, -2, 0, -2 },
    { 2, -1, 2, 0 }, { 2, 1, 2, 0 }
};

inline bool in_black_palace(const int r, const int c) {
    return r >= 1 && r <= 3 && c >= 4 && c <= 6;
}

int cnt_of_blocks(const vector<vector<char>>& board,
                  int r1, int c1, int r2, int c2) {
    int cnt = 0;
    if (r1 != r2 && c1 != c2) {
        return -1;
    }
    if (r1 == r2) {
        if (c1 > c2) {
            swap(c1, c2);
        }
        for (int i = c1 + 1; i < c2; ++i) {
            if (board[r1][i]) {
                ++cnt;
            }
        }
    } else if (c1 == c2) {
        if (r1 > r2) {
            swap(r1, r2);
        }
        for (int i = r1 + 1; i < r2; ++i) {
            if (board[i][c1]) {
                ++cnt;
            }
        }
    }
    return cnt;
}

bool G(const vector<vector<char>>& board, const int r, const int c,
       const int x, const int y) {
    return cnt_of_blocks(board, r, c, x, y) == 0;
}

bool R(const vector<vector<char>>& board, const int r, const int c,
       const int x, const int y) {
    return cnt_of_blocks(board, r, c, x, y) == 0;
}

bool C(const vector<vector<char>>& board, const int r, const int c,
       const int x, const int y) {
    return cnt_of_blocks(board, r, c, x, y) == 1;
}

bool H(const vector<vector<char>>& board, const int r, const int c,
       const int x, const int y) {
    for (const auto& d : Hdir) {
        int x1 = x + d[0], y1 = y + d[1];
        int x2 = x + d[2], y2 = y + d[3];
        if (x1 == r && y1 == c &&
            cnt_of_blocks(board, x, y, x2, y2) == 0)  {
            return true;
        }
    }
    return false;
}

bool check_red_win(const vector<Piece>& pieces,
                   const vector<vector<char>>& board,
                   const int r, const int c) {
    for (const auto& p : pieces) {
        if (!(p.r == r && p.c == c)) {
            if ((p.type == 'G' && G(board, r, c, p.r, p.c)) ||
                (p.type == 'R' && R(board, r, c, p.r, p.c)) ||
                (p.type == 'C' && C(board, r, c, p.r, p.c)) ||
                (p.type == 'H' && H(board, r, c, p.r, p.c))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, r0, c0, G_idx;
    while (cin >> N >> r0 >> c0 && (N != 0)) {
        vector<Piece> pieces;
        vector<vector<char>> board(12, vector<char>(12));
        for (int i = 0; i < N; ++i) {
            Piece p;
            cin >> p.type >> p.r >> p.c;
            if (p.type == 'G') {
                G_idx = i;
            }
            board[p.r][p.c] = p.type;
            pieces.emplace_back(p);
        }
        if (G(board, r0, c0, pieces[G_idx].r, pieces[G_idx].r)) {
            cout << "NO" << endl;
            continue;
        }
        bool pieces_win = true;
        for (const auto& d : dir) {
            int r1 = r0 + d[0], c1 = c0 + d[1];
            if (in_black_palace(r1, c1) &&
                !check_red_win(pieces, board, r1, c1)) {
                pieces_win = false;
                break;
            }
        }
        cout << (pieces_win ? "YES" : "NO") << endl;
    }
    return 0;
}
