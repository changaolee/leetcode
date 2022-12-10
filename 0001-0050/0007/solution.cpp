#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

struct Example {
    int x;
    int ans;
};

int main() {
    vector<Example> examples = {
        {123, 321},
        {-123, -321},
        {120, 21},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        int ans = solve->reverse(examples[i].x);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}