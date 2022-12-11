#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                long long sum = (long long)target - nums[i] - nums[j];
                while (l < r) {
                    if (nums[l] + nums[r] == sum) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++, r--;
                    } else if (nums[l] + nums[r] < sum) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};

struct Example {
    vector<int> nums;
    int target;
    vector<vector<int>> ans;
};

int main() {
    vector<Example> examples = {
        {{1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}},
        {{2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}}},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        vector<vector<int>> ans = solve->fourSum(examples[i].nums, examples[i].target);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}