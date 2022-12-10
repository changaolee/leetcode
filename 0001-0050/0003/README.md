## 题目

[3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

---

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长子串** 的长度。

**示例 1:**

```txt
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```txt
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```txt
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

**提示：**

- `0 <= s.length <= 5 * 10^4`
- `s` 由英文字母、数字、符号和空格组成

## 解析

使用一个数组记录每个字符上次出现的位置，在遍历的同时移动窗口左边界，最后返回窗口长度的最大值即可。

## 代码

### C++

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128, -1);
        int ans = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            j = max(j, pos[s[i]] + 1);
            ans = max(ans, i - j + 1);
            pos[s[i]] = i;
        }
        return ans;
    }
};
```

### Go

```go
func lengthOfLongestSubstring(s string) (ans int) {
    pos := map[byte]int{}
    for i, j := 0, 0; i < len(s); i++ {
        if p, ok := pos[s[i]]; ok {
            j = max(j, p+1)
        }
        ans = max(ans, i-j+1)
        pos[s[i]] = i
    }
    return
}

func max(x, y int) int {
    if x < y {
        return y
    }
    return x
}
```

### Python

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        pos = [-1] * 128
        ans = 0
        i, j = 0, 0
        while i < len(s):
            j = max(j, pos[ord(s[i])] + 1)
            ans = max(ans, i - j + 1)
            pos[ord(s[i])] = i
            i += 1
        return ans
```