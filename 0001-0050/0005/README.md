## 题目

[5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)

---

给你一个字符串 `s`，找到 `s` 中最长的回文子串。

**示例 1：**

```txt
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

**示例 2：**

```txt
输入：s = "cbbd"
输出："bb"
```

**提示：**

- `1 <= s.length <= 1000`
- `s` 仅由数字和英文字母组成

## 解析

中心扩展法，枚举回文子串的中心位置，每次循环需要分奇数和偶数两种情况。

## 代码

### C++

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            // 奇数长度的回文串
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
            if (ans.length() < r - l - 1) ans = s.substr(l + 1, r - l - 1);

            // 偶数长度的回文串
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
            if (ans.length() < r - l - 1) ans = s.substr(l + 1, r - l - 1);
        }
        return ans;
    }
};
```

### Go

```go
func longestPalindrome(s string) (ans string) {
    for i := 0; i < len(s); i++ {
        // 奇数长度
        l, r := i-1, i+1
        for l >= 0 && r < len(s) && s[l] == s[r] {
            l--
            r++
        }
        if len(ans) < r-l-1 {
            ans = s[l+1 : r]
        }

        // 偶数长度
        l, r = i, i+1
        for l >= 0 && r < len(s) && s[l] == s[r] {
            l--
            r++
        }
        if len(ans) < r-l-1 {
            ans = s[l+1 : r]
        }
    }
    return
}
```

### Python

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        for i in range(len(s)):
            # 奇数长度的回文串
            l, r = i - 1, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            if len(ans) < r - l - 1:
                ans = s[l + 1:r]

            # 偶数长度的回文串
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            if len(ans) < r - l - 1:
                ans = s[l + 1:r]
        return ans
```