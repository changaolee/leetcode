#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && value[s[i]] < value[s[i + 1]]) {
                ans -= value[s[i]];
            } else {
                ans += value[s[i]];
            }
        }
        return ans;
    }
};

struct Example {
    string num;
    int ans;
};

int main() {
    vector<Example> examples = {
        {"III", 3},
        {"LVIII", 58},
        {"MCMXCIV", 1994},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        int ans = solve->romanToInt(examples[i].num);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}