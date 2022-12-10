## 题目

[11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)

---

给定一个长度为 `n` 的整数数组 `height` 。有 `n` 条垂线，第 `i` 条线的两个端点是 `(i, 0)` 和 `(i, height[i])` 。

找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

**说明：** 你不能倾斜容器。

**示例 1：**

![](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

```txt
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
```

**示例 2：**

```txt
输入：height = [1,1]
输出：1
```

**提示：**

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

## 解析

使用首尾双指针，具体过程如下：

- 求出当前双指针对应的容器的容量；
- 由于对应数字较小的那个指针以后不可能作为容器的边界了，将其丢弃，并移动对应的指针。

## 代码

### C++

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return ans;
    }
};
```

### Go

```go
func maxArea(height []int) (ans int) {
    l, r := 0, len(height)-1
    for l < r {
        ans = max(ans, min(height[l], height[r])*(r-l))
        if height[l] < height[r] {
            l++
        } else {
            r--
        }
    }
    return
}

func max(x, y int) int {
    if x < y {
        return y
    }
    return x
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
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        l, r = 0, len(height) - 1
        while l < r:
            ans = max(ans, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans
```