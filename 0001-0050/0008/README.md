## 题目

[8. 字符串转换整数 (atoi)](https://leetcode.cn/problems/string-to-integer-atoi/)

---

请你来实现一个 `myAtoi(string s)` 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 `atoi` 函数）。

函数 `myAtoi(string s)` 的算法如下：

1.  读入字符串并丢弃无用的前导空格
2.  检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
3.  读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
4.  将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 `0` 。必要时更改符号（从步骤 2 开始）。
5.  如果整数数超过 32 位有符号整数范围 `[−2^31,  2^31 − 1]` ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 `−2^31` 的整数应该被固定为 `−2^31` ，大于 `2^31 − 1` 的整数应该被固定为 `2^31 − 1` 。
6.  返回整数作为最终结果。

**注意：**

- 本题中的空白字符只包括空格字符 `' '` 。
- 除前导空格或数字后的其余字符串外，**请勿忽略** 任何其他字符。

**示例 1：**

```txt
输入：s = "42"
输出：42
解释：加粗的字符串为已经读入的字符，插入符号是当前读取的字符。
第 1 步："42"（当前没有读入字符，因为没有前导空格）
         ^
第 2 步："42"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
         ^
第 3 步："42"（读入 "42"）
           ^
解析得到整数 42 。
由于 "42" 在范围 [-231, 231 - 1] 内，最终结果为 42 。
```

**示例 2：**

```txt
输入：s = "   -42"
输出：-42
解释：
第 1 步："   -42"（读入前导空格，但忽视掉）
            ^
第 2 步："   -42"（读入 '-' 字符，所以结果应该是负数）
             ^
第 3 步："   -42"（读入 "42"）
               ^
解析得到整数 -42 。
由于 "-42" 在范围 [-231, 231 - 1] 内，最终结果为 -42 。
```

**示例 3：**

```txt
输入：s = "4193 with words"
输出：4193
解释：
第 1 步："4193 with words"（当前没有读入字符，因为没有前导空格）
         ^
第 2 步："4193 with words"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
         ^
第 3 步："4193 with words"（读入 "4193"；由于下一个字符不是一个数字，所以读入停止）
             ^
解析得到整数 4193 。
由于 "4193" 在范围 [-231, 231 - 1] 内，最终结果为 4193 。
```

**提示：**

- `0 <= s.length <= 200`
- `s` 由英文字母（大写和小写）、数字（`0-9`）、`' '`、`'+'`、`'-'` 和 `'.'` 组成

## 解析

按照规则实现即可，为了实现方便，有以下几个注意点：

1. 使用 long long 存储结果，方便进行越界判断；
2. 使用额外变量标记正负号，在最后返回时与结果相乘。

## 代码

### C++

```cpp
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;

        // 去除前导空格
        int start = 0;
        while (start < s.length() && s[start] == ' ') start++;
        if (start == s.length()) return 0;

        // 判断正负号
        int sign = 1;
        if (s[start] == '-') sign = -1, start++;
        else if (s[start] == '+') start++;

        // 读取数字 
        for (int i = start; i < s.length() && isdigit(s[i]); i++) {
            ans = ans * 10 + sign * (s[i] - '0');
            if (ans > 0 && ans >= INT_MAX) return INT_MAX;
            if (ans < 0 && ans <= INT_MIN) return INT_MIN;
        }

        return ans;
    }
};
```

### Go

```go
func myAtoi(s string) (ans int) {
    rs := bytes.Runes([]byte(s))
    start := 0
    for start < len(rs) && rs[start] == ' ' {
        start++
    }
    if start == len(rs) {
        return
    }
    sign := 1
    if rs[start] == '-' {
        sign = -1
        start++
    } else if rs[start] == '+' {
        start++
    }
    for i := start; i < len(rs) && unicode.IsDigit(rs[i]); i++ {
        if sign > 0 && ans > (math.MaxInt32-int(rs[i]-'0'))/10 {
            ans = math.MaxInt32
            break
        }
        if sign < 0 && ans < (math.MinInt32+int(rs[i]-'0'))/10 {
            ans = math.MinInt32
            break
        }
        ans = ans*10 + sign*int(rs[i]-'0')
    }
    return
}
```

### Python

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MIN, INT_MAX = -2 ** 31, 2 ** 31 - 1
        ans = 0

        # 去除前导空格
        start = 0
        while start < len(s) and s[start] == ' ':
            start += 1
        if start == len(s):
            return 0

        # 判断正负号
        sign = 1
        if s[start] == '-':
            sign = -1
            start += 1
        elif s[start] == '+':
            start += 1

        # 读取数字
        for i in range(start, len(s)):
            if not str.isdigit(s[i]):
                break
            ans = ans * 10 + sign * int(s[i])
            if ans > 0 and ans >= INT_MAX:
                return INT_MAX
            if ans < 0 and ans <= INT_MIN:
                return INT_MIN

        return ans
```