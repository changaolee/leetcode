## 题目

[7. 整数反转](https://leetcode.cn/problems/reverse-integer/)

---

给你一个 32 位的有符号整数 `x` ，返回将 `x` 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 `[−2^31,  2^31 − 1]` ，就返回 0。

**假设环境不允许存储 64 位整数（有符号或无符号）。**  

**示例 1：**

```txt
输入：x = 123
输出：321
```

**示例 2：**

```txt
输入：x = -123
输出：-321
```

**示例 3：**

```txt
输入：x = 120
输出：21
```

**示例 4：**

```txt
输入：x = 0
输出：0
```

**提示：**

- `-2^31 <= x <= 2^31 - 1`

## 解析

构建反转整数的一位数字，同时需要预先检查向原整数附加另一位数字是否会导致溢出。

## 代码

### C++

```cpp
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
```

### Go

```go
func reverse(x int) (ans int) {
    for x != 0 {
        if x > 0 && ans > (math.MaxInt32-x%10)/10 {
            return 0
        }
        if x < 0 && ans < (math.MinInt32-x%10)/10 {
            return 0
        }
        ans = ans*10 + x%10
        x /= 10
    }
    return
}
```

### Python

```python
class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2 ** 31, 2 ** 31 - 1
        ans = 0
        while x:
            digit = x % 10
            if x < 0 and digit > 0:
                digit -= 10
            if x > 0 and ans > (INT_MAX - digit) // 10:
                return 0
            if x < 0 and ans < -((INT_MIN - digit) // -10):
                return 0
            ans = ans * 10 + digit
            x = x // 10 if x > 0 else -(x // -10)
        return ans
```