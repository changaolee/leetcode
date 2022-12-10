#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int num = x, cur = 0;
        while (x) {
            if (cur > (INT_MAX - x % 10) / 10) return false;
            cur = cur * 10 + x % 10;
            x /= 10;
        }
        return cur == num;
    }
};

struct Example {
    int x;
    bool ans;
};

int main() {
    vector<Example> examples = {
        {121, true},
        {-121, false},
        {10, false},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        bool ans = solve->isPalindrome(examples[i].x);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}