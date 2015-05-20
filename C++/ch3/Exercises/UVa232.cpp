// UVa232 - Crossword Answers
// Time:  O(m * n)
// Space: O(n)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void PrintAcross(vector<string> &crossword) {
    cout << "Across" << endl;
    int count = 0;
    for (int i = 0; i < crossword.size(); ++i) {
        for (int j = 0; j < crossword[i].length(); ++j) {
            if (crossword[i][j] != '*') {
                // numbering increases near the border or '*'
                if (i - 1 < 0 || crossword[i - 1][j] == '*' ||
                    j - 1 < 0 || crossword[i][j - 1] == '*') {
                    ++count;
                }
                
                int numbering = count;
                string answer;
                answer.push_back(crossword[i][j++]);
                while (j < crossword[i].length() && crossword[i][j] != '*') { //Across.
                    if (i - 1 < 0 || crossword[i - 1][j] == '*' ||
                        j - 1 < 0 || crossword[i][j - 1] == '*') {
                        ++count;
                    }
                    answer.push_back(crossword[i][j++]);
                }
                cout << setw(3) << numbering << "."
                     << answer << endl;
            }
        }
    }
}

void PrintDown(vector<string> &crossword) {
    cout << "Down" << endl;
    // valid_index[j] denoted as foreah i >= valid_index[j], the square crossword[i][j] is unused.
    vector<int> valid_index(crossword[0].length(), 0);
    int count = 0;
    for (int i = 0; i < crossword.size(); ++i) {
        for (int j = 0; j < crossword[i].length(); ++j) {
            if (crossword[i][j] != '*') {
                // numbering increases near the border or '*'
                if (i - 1 < 0 || crossword[i - 1][j] == '*' ||
                    j - 1 < 0 || crossword[i][j - 1] == '*') {
                    ++count;
                }
                
                // The square crossword[i][j] is unused.
                if (i >= valid_index[j]) {
                    int numbering = count;
                    string answer;
                    int k = i;
                    answer.push_back(crossword[k++][j]);
                    while (k < crossword.size() && crossword[k][j] != '*') { // Down.
                        answer.push_back(crossword[k++][j]);
                    }
                    valid_index[j] = k;
                    cout << setw(3) << numbering << "."
                         << answer << endl;
                }
            }
        }
    }
}

void PrintAnswers(vector<string> &crossword) {
    PrintAcross(crossword);
    PrintDown(crossword);
}

int main() {
    int T = 0;
    int r, c;
    
    while (cin >> r >> c) {
        vector<string> crossword(r, string());
        for (int i = 0; i < crossword.size(); ++i) {
            cin >> crossword[i];
        }
        if (++T > 1) {
            cout << endl;
        }
        cout << "puzzle #" << T << ":" << endl;
        PrintAnswers(crossword);
    }
    
    return 0;
}