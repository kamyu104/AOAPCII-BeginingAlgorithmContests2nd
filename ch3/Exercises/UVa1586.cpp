// UVa1586 - Molar Mass

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

double AtomicWeightOf(char atom) {
    if (atom == 'C') {
        return 12.01;
    } else if (atom == 'H') {
        return 1.008;
    } else if (atom == 'O') {
        return 16.00;
    }
    return 14.01;
}


int main ()
{
    int t;
    string formula;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> formula;
        double result = 0;
        int j = 0;
        
        while (j < formula.length()) {
            string temp_str = "0";
            int temp_index = j + 1;
            while (temp_index < formula.length() && isdigit(formula[temp_index])) {
                temp_str.append(1, formula[temp_index]);
                ++temp_index;
            }
            
            double multiplier = atof(temp_str.c_str());
            
            if (multiplier == 0.0) {
                multiplier = 1.0;
            }
            result += multiplier * AtomicWeightOf(formula[j]);
            
            j = temp_index;
        }
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(3);
        cout << result << endl;
    }
}