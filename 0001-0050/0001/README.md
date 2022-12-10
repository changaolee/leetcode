## 题目

[1. 两数之和](https://leetcode.cn/problems/two-sum/)

---

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`*  的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

**示例 1：**

```txt
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```txt
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```txt
输入：nums = [3,3], target = 6
输出：[0,1]
```

**提示：**

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- **只会存在一个有效答案**

**进阶：** 你可以想出一个时间复杂度小于 `O(n^2)` 的算法吗？

## 解析

使用 Hash 表记录所有已遍历元素及对应的下标，遍历的同时查找满足条件的数字是否已遍历，若找到返回即可。

## 代码

### C++

```cpp
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
```

### Go

```go
func twoSum(nums []int, target int) (ans []int) {
    record := map[int]int{}
    for i, num := range nums {
        if p, ok := record[target-num]; ok {
            return []int{p, i}
        }
        record[num] = i
    }
    return nil
}
```

### Python

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        record = {}
        for i, num in enumerate(nums):
            x = target - num
            if x in record:
                return [record[x], i]
            record[num] = i
        return [-1, -1]
```