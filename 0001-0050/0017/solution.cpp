#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<string> ans;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        ans = vector<string>();
        if (digits.empty()) return ans;
        dfs(digits, 0, "");
        return ans;
    }
    
    void dfs(string &digits, int idx, string combine) {
        if (idx == digits.length()) {
            ans.push_back(combine);
            return;
        }
        string s = strs[digits[idx] - '0'];
        for (int i = 0; i < s.length(); i++) {
            combine.push_back(s[i]);
            dfs(digits, idx + 1, combine);
            combine.pop_back();
        }
    }
};

struct Example {
    string digits;
    vector<string> ans;
};

int main() {
    vector<Example> examples = {
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        {"", {}},
        {"2", {"a", "b", "c"}},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        vector<string> ans = solve->letterCombinations(examples[i].digits);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}