// UVa1368 - DNA Consensus String
// Time:  O(m * n)
// Space: O(1)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void ConsensusString(vector<string>& DNAs, string& consensus_string, int& error_count) {
    for (int j = 0; j < DNAs[0].length(); ++j) {
        // Count.
        unordered_map<char, int> count;
        for (int i = 0; i < DNAs.size(); ++i) {
            ++count[DNAs[i][j]];
        }
        
        // Find smallest consensus nucleotide.
        char consensus = 'A';
        for (const auto& nucleotide : {'A', 'C', 'G', 'T'}) { // Be aware of the order.
            if (count[nucleotide] > count[consensus]) {
                consensus = nucleotide;
            }
        }
        
        // Update info.
        consensus_string[j] = consensus;
        error_count += DNAs.size() - count[consensus];
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
        ConsensusString(DNAs, consensus_string, error_count);
        cout << consensus_string << endl;
        cout << error_count << endl;
    }
    
    return 0;
}