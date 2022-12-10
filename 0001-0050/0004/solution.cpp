#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 0) {
            int left = find(nums1, 0, nums2, 0, n / 2);
            int right = find(nums1, 0, nums2, 0, n / 2 + 1);
            return (left + right) / 2.0;
        } else {
            return find(nums1, 0, nums2, 0, n / 2 + 1);
        }
    }
    
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        // 保证 nums1 的元素更少，方便处理
        if (nums1.size() - i > nums2.size() - j) return find(nums2, j, nums1, i, k);
        
        // nums1 为空，直接取 nums2 的第 k 个元素
        if (nums1.size() == i) return nums2[j + k - 1];
        
        // k = 1 时，取两数组第一个元素的最小值
        if (k == 1) return min(nums1[i], nums2[j]);
        
        // 分别对应两数组 k / 2 的下一个位置
        int si = min((int)nums1.size(), i + k / 2);
        int sj = j + k - k / 2;
        if (nums1[si - 1] < nums2[sj - 1]) {
            return find(nums1, si, nums2, j, k - (si - i));
        } else {
            return find(nums1, i, nums2, sj, k - (sj - j));
        }
    }
};

struct Example {
    vector<int> nums1, nums2;
    double ans;
};

int main() {
    vector<Example> examples = {
        {{1, 3}, {2}, 2.},
        {{1, 2}, {3, 4}, 2.5},
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        double ans = solve->findMedianSortedArrays(examples[i].nums1, examples[i].nums2);
        if (abs(ans - examples[i].ans) <= 1e-8) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}