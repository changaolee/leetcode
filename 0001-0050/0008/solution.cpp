#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        
        // 去除前导空格
        int start = 0;
        while (start < s.length() && s[start] == ' ') start++;
        if (start == s.length()) return 0;
        
        // 判断正负号
        int sign = 1;
        if (s[start] == '-') sign = -1, start++;
        else if (s[start] == '+') start++;
        
        // 读取数字 
        for (int i = start; i < s.length() && isdigit(s[i]); i++) {
            ans = ans * 10 + sign * (s[i] - '0');
            if (ans > 0 && ans >= INT_MAX) return INT_MAX;
            if (ans < 0 && ans <= INT_MIN) return INT_MIN;
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
        {"42", 42},
        {"   -42", -42},
        {"4193 with words", 4193},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        int ans = solve->myAtoi(examples[i].s);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}