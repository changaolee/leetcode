#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;
                if (abs(sum - target) < abs(ans - target)) ans = sum;
                if (sum < target) l++;
                else r--;
            }
        }
        return ans;
    }
};

struct Example {
    vector<int> nums;
    int target;
    int ans;
};

int main() {
    vector<Example> examples = {
        {{-1, 2, 1, -4}, 1, 2},
        {{0, 0, 0}, 1, 0},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        int ans = solve->threeSumClosest(examples[i].nums, examples[i].target);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}