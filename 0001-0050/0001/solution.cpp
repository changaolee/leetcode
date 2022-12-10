#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (record.find(num) != record.end()) {
                return vector<int>{record[num], i};
            }
            record[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};

struct Example {
    vector<int> nums;
    int target;
    vector<int> ans;
};

int main() {
    vector<Example> examples = {
        {{2, 7, 11, 15}, 9, {0, 1}},
        {{3, 2, 4}, 6, {1, 2}},
        {{3, 3}, 6, {0, 1}},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        vector<int> ans = solve->twoSum(examples[i].nums, examples[i].target);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}