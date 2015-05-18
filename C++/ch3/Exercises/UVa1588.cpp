// UVa1588 - Kickdown
// Time:  O(m * n)
// Space: O(1)

#include <iostream>
#include <string>

using namespace std;

bool IsValid(int k, const string& s1, const string& s2){
    for (int i = 0; k + i < s1.length() && i < s2.length(); ++i) {
        if ((s1[k + i] - '0') + (s2[i] - '0') > 3) {
            return false;
        }
    }
    return true;
}

size_t Cut(const string& s1, const string& s2){
    int k = 0;
    while (!IsValid(k, s1, s2)) {
        ++k;
    }
    return max(s1.length(), s2.length() + k);
}

int main(){
    string bottom, top;
    while (cin >> bottom >> top) {
        cout << min(Cut(bottom, top), Cut(top, bottom)) << endl;
    }
    return 0;
}