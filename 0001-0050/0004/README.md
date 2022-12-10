## 题目

[4. 寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)

---

给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

算法的时间复杂度应该为 `O(log (m+n))` 。

**示例 1：**

```txt
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
```

**示例 2：**

```txt
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
```

**提示：**

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

## 解析

本题可以抽象为：给定两个数组 A、B，如何找到从小到大排列的第 $k$ 个数？

只要让 $k$ 取值 $(n + m) / 2$，就可以得到中位数。令 $k_1 = k / 2$，$k_2 = k - k / 2$，则：

- 当 $A[k_1] < B[k_2]$ 时，去掉 $A[\le{k_1}]$ 的元素；
- 当 $A[k_1] > B[k_2]$ 时，去掉 $B[\le{k_2}]$ 的元素；
- 当 $A[k_1] = B[k_2]$ 时，去掉 $A[\le{k_1}]$ 或 $B[\le{k_2}]$ 的元素。

综上，可以将其转化为一个递归的问题，每次 $k$ 的规模都减少一半，而 $k$ 取值 $(n + m) / 2$，因此时间复杂度为 $O(log(m+n))$。

## 代码

### C++

```cpp
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
```

### Go

```go
func findMedianSortedArrays(x []int, y []int) (ans float64) {
    n := len(x) + len(y)
    if n%2 == 0 {
        left := find(x, 0, y, 0, n/2)
        right := find(x, 0, y, 0, n/2+1)
        ans = float64(left+right) / 2.0
    } else {
        ans = find(x, 0, y, 0, n/2+1)
    }
    return
}

func find(x []int, i int, y []int, j int, k int) float64 {
    if len(x)-i > len(y)-j {
        return find(y, j, x, i, k)
    }
    if len(x)-i == 0 {
        return float64(y[j+k-1])
    }
    if k == 1 {
        return float64(min(x[i], y[j]))
    }
    si := min(len(x), i+k/2)
    sj := j + k - k/2
    if x[si-1] < y[sj-1] {
        return find(x, si, y, j, k-(si-i))
    } else {
        return find(x, i, y, sj, k-(sj-j))
    }
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```

### Python

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1) + len(nums2)
        if n % 2 == 0:
            left = self.find(nums1, 0, nums2, 0, n // 2)
            right = self.find(nums1, 0, nums2, 0, n // 2 + 1)
            return (left + right) / 2
        else:
            return self.find(nums1, 0, nums2, 0, n // 2 + 1)

    def find(self, nums1, i, nums2, j, k):
        if len(nums1) - i > len(nums2) - j:
            return self.find(nums2, j, nums1, i, k)
        if len(nums1) == i:
            return nums2[j + k - 1]
        if k == 1:
            return min(nums1[i], nums2[j])

        si = min(len(nums1), i + k // 2)
        sj = j + k - k // 2
        if nums1[si - 1] < nums2[sj - 1]:
            return self.find(nums1, si, nums2, j, k - (si - i))
        else:
            return self.find(nums1, i, nums2, sj, k - (sj - j))
```