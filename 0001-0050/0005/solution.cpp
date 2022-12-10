#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            // 奇数长度的回文串
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
            if (ans.length() < r - l - 1) ans = s.substr(l + 1, r - l - 1);
            
            // 偶数长度的回文串
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
            if (ans.length() < r - l - 1) ans = s.substr(l + 1, r - l - 1);
        }
        return ans;
    }
};

struct Example {
    string s;
    string ans;
};

int main() {
    vector<Example> examples = {
        {"babad", "bab"},
        {"cbbd", "bb"},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        string ans = solve->longestPalindrome(examples[i].s);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}