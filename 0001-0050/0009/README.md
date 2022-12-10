## 题目

[9. 回文数](https://leetcode.cn/problems/palindrome-number/)

---

给你一个整数 `x` ，如果 `x` 是一个回文整数，返回 `true` ；否则，返回 `false` 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

- 例如，`121` 是回文，而 `123` 不是。

**示例 1：**

```txt
输入：x = 121
输出：true
```

**示例 2：**

```txt
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```

**示例 3：**

```txt
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。
```

**提示：**

- `-2^31 <= x <= 2^31 - 1`

**进阶：** 你能不将整数转为字符串来解决这个问题吗？

## 解析

本题可以借鉴 [0007. 整数反转](../0007) 的做法，将数字反转后判断是否与原数字相等。

## 代码

### C++

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int num = x, cur = 0;
        while (x) {
            if (cur > (INT_MAX - x % 10) / 10) return false;
            cur = cur * 10 + x % 10;
            x /= 10;
        }
        return cur == num;
    }
};
```

### Go

```go
func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }
    num, cur := x, 0
    for x != 0 {
        if cur > (math.MaxInt32-x%10)/10 {
            return false
        }
        cur = cur*10 + x%10
        x /= 10
    }
    return num == cur
}
```

### Python

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        INT_MAX = 2 ** 31 - 1
        if x < 0:
            return False
        num, cur = x, 0
        while x:
            if cur > (INT_MAX - x % 10) // 10:
                return False
            cur = cur * 10 + x % 10
            x //= 10
        return cur == num
```