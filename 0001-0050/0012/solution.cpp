#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string thousands[] = {"", "M", "MM", "MMM"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};

struct Example {
    int num;
    string ans;
};

int main() {
    vector<Example> examples = {
        {3, "III"},
        {58, "LVIII"},
        {1994, "MCMXCIV"},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        string ans = solve->intToRoman(examples[i].num);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}