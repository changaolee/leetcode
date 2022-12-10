#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128, -1);
        int ans = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            j = max(j, pos[s[i]] + 1);
            ans = max(ans, i - j + 1);
            pos[s[i]] = i;
        }
        return ans;
    }
};

struct Example {
    string s;
    int ans;
};

int main() {
    vector<Example> examples = {
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        int ans = solve->lengthOfLongestSubstring(examples[i].s);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}