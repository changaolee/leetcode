## 题目

[18. 四数之和](https://leetcode.cn/problems/4sum/)

---

给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

- `0 <= a, b, c, d < n`
- `a`、`b`、`c` 和 `d` **互不相同**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按 **任意顺序** 返回答案 。

**示例 1：**

```txt
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**

```txt
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```

**提示：**

- `1 <= nums.length <= 200`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`

## 解析

本题思路与 [0015. 三数之和](../0015) 相同，只需增加一层循环，枚举前两个数字的值，双指针确定后两个数字的值即可。

## 代码

### C++

```cpp
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
```

### Go

```go
func fourSum(nums []int, target int) (ans [][]int) {
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        for j := i + 1; j < len(nums); j++ {
            if j > i+1 && nums[j] == nums[j-1] {
                continue
            }
            l, r := j+1, len(nums)-1
            sum := target - nums[i] - nums[j]
            for l < r {
                if nums[l]+nums[r] == sum {
                    ans = append(ans, []int{nums[i], nums[j], nums[l], nums[r]})
                    for l < r && nums[l] == nums[l+1] {
                        l++
                    }
                    for l < r && nums[r] == nums[r-1] {
                        r--
                    }
                    l++
                    r--
                } else if nums[l]+nums[r] < sum {
                    l++
                } else {
                    r--
                }
            }
        }
    }
    return
}
```

### Python

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums)):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                l, r = j + 1, len(nums) - 1
                _sum = target - nums[i] - nums[j]
                while l < r:
                    if nums[l] + nums[r] == _sum:
                        ans.append([nums[i], nums[j], nums[l], nums[r]])
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        l += 1
                        r -= 1
                    elif nums[l] + nums[r] < _sum:
                        l += 1
                    else:
                        r -= 1
        return ans
```