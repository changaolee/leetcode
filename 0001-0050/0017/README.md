## 题目

[17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

---

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png)

**示例 1：**

```txt
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```txt
输入：digits = ""
输出：[]
```

**示例 3：**

```txt
输入：digits = "2"
输出：["a","b","c"]
```

**提示：**

- `0 <= digits.length <= 4`
- `digits[i]` 是范围 `['2', '9']` 的一个数字。

## 解析

首先存储每个数字对应的所有可能的字母，然后进行回溯操作。回溯过程中维护一个字符串，表示已有的字母排列，并记录当前回溯位置。每次尝试对应位置数字的所有字母，即可得到完整排列。

## 代码

### C++

```cpp
class Solution {
    vector<string> ans;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        ans = vector<string>();
        if (digits.empty()) return ans;
        dfs(digits, 0, "");
        return ans;
    }
    
    void dfs(string &digits, int idx, string combine) {
        if (idx == digits.length()) {
            ans.push_back(combine);
            return;
        }
        string s = strs[digits[idx] - '0'];
        for (int i = 0; i < s.length(); i++) {
            combine.push_back(s[i]);
            dfs(digits, idx + 1, combine);
            combine.pop_back();
        }
    }
};
```

### Go

```go
var ans []string
var strs = []string{
    "", "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz",
}

func letterCombinations(digits string) []string {
    ans = []string{}
    if len(digits) == 0 {
        return ans
    }
    dfs(digits, 0, "")
    return ans
}

func dfs(digits string, idx int, combine string) {
    if idx == len(digits) {
        ans = append(ans, combine)
        return
    }
    s := strs[digits[idx]-'0']
    for i := 0; i < len(s); i++ {
        combine += string(s[i])
        dfs(digits, idx+1, combine)
        combine = combine[:len(combine)-1]
    }
}
```

### Python

```python
class Solution:
    ans = []
    strs = [
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    ]

    def letterCombinations(self, digits: str) -> List[str]:
        self.ans = []
        if not digits:
            return self.ans
        self.dfs(digits, 0, "")
        return self.ans

    def dfs(self, digits, idx, combine):
        if idx == len(digits):
            self.ans.append(combine)
            return
        s = self.strs[int(digits[idx])]
        for i in range(len(s)):
            combine += s[i]
            self.dfs(digits, idx + 1, combine)
            combine = combine[:-1]
```