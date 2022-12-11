## 题目

[20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

---

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
3. 每个右括号都有一个对应的相同类型的左括号。

**示例 1：**

```txt
输入：s = "()"
输出：true
```

**示例 2：**

```txt
输入：s = "()[]{}"
输出：true
```

**示例 3：**

```txt
输入：s = "(]"
输出：false
```

**提示：**

- `1 <= s.length <= 10^4`
- `s` 仅由括号 `'()[]{}'` 组成

## 解析

遍历字符串，每遇到一个左括号时，将与其匹配的右括号入栈；当遇到右括号时，与栈顶元素比较配对，不一致则匹配失败。

## 代码

### C++

```cpp
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {'(', ')'}, {'{', '}'}, {'[', ']'}
        };
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (pairs.find(s[i]) != pairs.end()) {
                stk.push(pairs[s[i]]);
            } else {
                if (stk.empty() || stk.top() != s[i]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
```

### Go

```go
func isValid(s string) bool {
    pairs := map[byte]byte{
        '(': ')', '{': '}', '[': ']',
    }
    var stk []byte
    for i := 0; i < len(s); i++ {
        if p, ok := pairs[s[i]]; ok {
            stk = append(stk, p)
        } else {
            if len(stk) == 0 || stk[len(stk)-1] != s[i] {
                return false
            }
            stk = stk[:len(stk)-1]
        }
    }
    return len(stk) == 0
}
```

### Python

```python
class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {
            '(': ')', '{': '}', '[': ']'
        }
        stk = []
        for i in range(len(s)):
            if s[i] in pairs:
                stk.append(pairs[s[i]])
            else:
                if not stk or stk[-1] != s[i]:
                    return False
                stk = stk[:-1]
        return not stk
```