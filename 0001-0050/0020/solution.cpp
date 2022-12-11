#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {'(', ')'}, {'{', '}'}, {'[', ']'}
        };
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (pairs.find(s[i]) != pairs.end()) {
                stk.push(pairs[s[i]]);
            } else {
                if (stk.empty() || stk.top() != s[i]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};

struct Example {
    string s;
    bool ans;
};

int main() {
    vector<Example> examples = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false}
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        bool ans = solve->isValid(examples[i].s);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}