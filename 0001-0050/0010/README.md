## 题目

[10. 正则表达式匹配](https://leetcode.cn/problems/regular-expression-matching/)

---

给你一个字符串 `s` 和一个字符规律 `p`，请你来实现一个支持 `'.'` 和 `'*'` 的正则表达式匹配。

- `'.'` 匹配任意单个字符
- `'*'` 匹配零个或多个前面的那一个元素

所谓匹配，是要涵盖 **整个** 字符串 `s`的，而不是部分字符串。

**示例 1：**

```txt
输入：s = "aa", p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
```

**示例 2:**

```txt
输入：s = "aa", p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
```

**示例 3：**

```txt
输入：s = "ab", p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
```

**提示：**

- `1 <= s.length <= 20`
- `1 <= p.length <= 30`
- `s` 只包含从 `a-z` 的小写字母。
- `p` 只包含从 `a-z` 的小写字母，以及字符 `.` 和 `*`。
- 保证每次出现字符 `*` 时，前面都匹配到有效的字符

## 解析

![](https://raw.githubusercontent.com/changaolee/leetcode/80dde54f279493573f783d6722bd881625a3712d/0001-0100/0010/images/leetcode_0010.svg)

## 代码

### C++

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j + 1 <= m && p[j + 1] == '*') continue;
                if (p[j] != '*') {
                    f[i][j] = i && j && f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else {
                    f[i][j] = (j >= 2 && f[i][j - 2]) || (i && j && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return f[n][m];
    }
};
```

### Go

```go
func isMatch(s string, p string) bool {
    n, m := len(s), len(p)
    s = string(' ') + s
    p = string(' ') + p
    f := make([][]bool, n+1)
    for i := range f {
        f[i] = make([]bool, m+1)
    }
    f[0][0] = true
    for i := 0; i <= n; i++ {
        for j := 1; j <= m; j++ {
            if j+1 <= m && p[j+1] == '*' {
                continue
            }
            if p[j] != '*' {
                f[i][j] = i > 0 && j > 0 && f[i-1][j-1] && (s[i] == p[j] || p[j] == '.')
            } else {
                f[i][j] = (j >= 2 && f[i][j-2]) || (i > 0 && j > 0 && f[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.'))
            }
        }
    }
    return f[n][m]
}
```

### Python

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        s, p = ' ' + s, ' ' + p
        f = [[False] * (m + 1) for _ in range(n + 1)]
        f[0][0] = True
        for i in range(n + 1):
            for j in range(1, m + 1):
                if j + 1 <= m and p[j + 1] == '*':
                    continue
                if p[j] != '*':
                    f[i][j] = i and j and f[i - 1][j - 1] and (s[i] == p[j] or p[j] == '.')
                else:
                    f[i][j] = (j >= 2 and f[i][j - 2]) or (
                            i and j and f[i - 1][j] and (s[i] == p[j - 1] or p[j - 1] == '.'))
        return bool(f[n][m])
```