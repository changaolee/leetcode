## 题目

[16. 最接近的三数之和](https://leetcode.cn/problems/3sum-closest/)

---

给你一个长度为 `n` 的整数数组 `nums` 和 一个目标值 `target`。请你从 `nums` 中选出三个整数，使它们的和与 `target` 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

**示例 1：**

```txt
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
```

**示例 2：**

```txt
输入：nums = [0,0,0], target = 1
输出：0
```

**提示：**

- `3 <= nums.length <= 1000`
- `-1000 <= nums[i] <= 1000`
- `-10^4 <= target <= 10^4`

## 解析

本题思路与 [0015. 三数之和](../0015) 类似，只是更新结果的条件变为比较差值的大小，保留差值更小的结果。

## 代码

### C++

```cpp
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
```

### Go

```go
func threeSumClosest(nums []int, target int) int {
    ans := nums[0] + nums[1] + nums[2]
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        l, r := i+1, len(nums)-1
        for l < r {
            sum := nums[i] + nums[l] + nums[r]
            if sum == target {
                return sum
            }
            if abs(sum-target) < abs(ans-target) {
                ans = sum
            }
            if sum < target {
                l++
            } else {
                r--
            }
        }
    }
    return ans
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
```

### Python

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = nums[0] + nums[1] + nums[2]
        nums.sort()
        for i in range(len(nums)):
            l, r = i + 1, len(nums) - 1
            while l < r:
                _sum = nums[i] + nums[l] + nums[r]
                if _sum == target:
                    return _sum
                if abs(_sum - target) < abs(ans - target):
                    ans = _sum
                if _sum < target:
                    l += 1
                else:
                    r -= 1
        return ans
```