// Copyright (c) 2015 kamyu. All rights reserved.

/*
 * UVa1587 - Box
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4462
 *
 * Time  : O(1)
 * Space : O(1)
 *
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_set;
using std::unordered_map;
using std::hash;
using std::pair;
using std::make_pair;
using std::swap;

struct HashPair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

// Make sure all of (w, h) has pairs.
bool CheckArea(const unordered_map<pair<int, int>, int, HashPair>& area) {
    return all_of(area.cbegin(), area.cend(),
                  [](const pair<pair<int, int>, int>& p) {
                      return p.second % 2 == 0;
                  });
}

// Make sure at most 3 different lengths of w, h, l,
// and all pairs of l, w, h exist.
bool CheckEdge(const unordered_map<pair<int, int>, int, HashPair>& area,
               const unordered_set<int>& edge) {
    if (edge.size() <= 3) {
        for (auto it = edge.cbegin(); it != edge.cend(); ++it) {
            auto jt = it;
            ++jt;
            for (; jt != edge.cend(); ++jt) {
                // Some of (w, h) does not exist.
                if (area.find(make_pair(*it, *jt)) == area.cend() &&
                    area.find(make_pair(*jt, *it)) == area.cend()) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

void CheckBox(const unordered_map<pair<int, int>, int, HashPair>& area,
              const unordered_set<int>& edge) {
        if (CheckArea(area) && CheckEdge(area, edge)) {
            cout << "POSSIBLE" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
}

int main() {
    int w, h;
    while (cin >> w >> h) {
        unordered_map<pair<int, int>, int, HashPair> area;
        unordered_set<int> edge;

        int count = 6;
        do {
            if (w > h) {
                swap(w, h);
            }
            ++area[make_pair(w, h)];
            edge.insert(w), edge.insert(h);
        } while (--count && cin >> w >> h);

        CheckBox(area, edge);
    }

    return 0;
}
