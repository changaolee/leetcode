#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows, "");
        bool down = false;
        for (int i = 0, row = 0; i < s.length(); i++) {
            rows[row] += s[i];
            if (row == 0 || row == numRows - 1) down = !down;
            row += down ? 1 : -1;
        }
        string ans = "";
        for (int i = 0; i < numRows; i++) ans += rows[i];
        return ans;
    }
};

struct Example {
    string s;
    int numRows;
    string ans;
};

int main() {
    vector<Example> examples = {
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"A", 1, "A"},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        string ans = solve->convert(examples[i].s, examples[i].numRows);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}