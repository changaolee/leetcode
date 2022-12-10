#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return ans;
    }
};

struct Example {
    vector<int> height;
    int ans;
};

int main() {
    vector<Example> examples = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
        {{1, 1}, 1},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        int ans = solve->maxArea(examples[i].height);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}