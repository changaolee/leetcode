#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            int target = 0 - nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++, r--;
                } else if (nums[l] + nums[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};

struct Example {
    vector<int> nums;
    vector<vector<int>> ans;
};

int main() {
    vector<Example> examples = {
        {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
        {{0, 1, 1}, {}},
        {{0, 0, 0}, {{0, 0, 0}}}
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        vector<vector<int>> ans = solve->threeSum(examples[i].nums);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}