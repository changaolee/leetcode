#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

struct Example {
    vector<string> strs;
    string ans;
};

int main() {
    vector<Example> examples = {
        {{"flower","flow","flight"}, "fl"},
        {{"dog","racecar","car"}, ""},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        string ans = solve->longestCommonPrefix(examples[i].strs);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}