// UVa1587 - Box
// Time:  O(1)
// Space: O(1)

#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct HashPair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int main() {
    int w, h;
    while (cin >> w >> h) {
        set<int> edge;
        unordered_map<pair<int, int>, int, HashPair> area;
        if (w > h) {
            swap(w, h);
        }
        edge.insert(w), edge.insert(h);
        ++area[make_pair(w, h)];
        
        int count = 5;
        while (count--) {
            cin >> w >> h;
            if (w > h) {
                swap(w, h);
            }
            edge.insert(w), edge.insert(h);
            ++area[make_pair(w, h)];
        }
        
        bool is_ok = false;
        // Make sure all of (w, h) has pairs and at most 3 different lengths of w, h, l.
        if (all_of(area.cbegin(), area.cend(), [](const pair<pair<int, int>, int>& i){ return i.second % 2 == 0; }) &&
            edge.size() <= 3) {
            is_ok = true;
            // Make sure all pairs of l, w, h exist.
            for (auto it = edge.cbegin(); is_ok && it != edge.cend(); ++it) {
                auto jt = it;
                ++jt;
                for (; is_ok && jt != edge.cend(); ++jt) {
                    if (area.find(make_pair(*it, *jt)) == area.cend()) { // Some of (w, h) does not exist.
                        is_ok = false;
                    }
                }
            }
        }
        
        if (is_ok) {
            cout << "POSSIBLE" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}