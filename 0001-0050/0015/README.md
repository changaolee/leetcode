## 题目

[15. 三数之和](https://leetcode.cn/problems/3sum/)

---

给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请

你返回所有和为 `0` 且不重复的三元组。

**注意：** 答案中不可以包含重复的三元组。

**示例 1：**

```txt
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

**示例 2：**

```txt
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
```

**示例 3：**

```txt
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
```

**提示：**

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

## 解析

由于需要求三个数字的和，遍历复杂度不会小于 `O(n^2)`，因此可以先对数组排序，这样方便之后处理。

整体思路为，通过遍历数组选取第一个数字，在遍历的同时用前后双指针寻找满足条件的数字即可。

## 代码

### C++

```cpp
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
```

### Go

```go
func threeSum(nums []int) (ans [][]int) {
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        l, r := i+1, len(nums)-1
        target := 0 - nums[i]
        for l < r {
            if nums[l]+nums[r] == target {
                ans = append(ans, []int{nums[i], nums[l], nums[r]})
                for l < r && nums[l] == nums[l+1] {
                    l++
                }
                for l < r && nums[r] == nums[r-1] {
                    r--
                }
                l++
                r--
            } else if nums[l]+nums[r] < target {
                l++
            } else {
                r--
            }
        }
    }
    return
}
```

### Python

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l, r = i + 1, len(nums) - 1
            target = 0 - nums[i]
            while l < r:
                if nums[l] + nums[r] == target:
                    ans.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif nums[l] + nums[r] < target:
                    l += 1
                else:
                    r -= 1
        return ans
```