## 题目

[6. Z 字形变换](https://leetcode.cn/problems/zigzag-conversion/)

---

将一个给定字符串 `s` 根据给定的行数 `numRows` ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 `"PAYPALISHIRING"` 行数为 `3` 时，排列如下：

```txt
P   A   H   N
A P L S I I G
Y   I   R
```

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"PAHNAPLSIIGYIR"`。

请你实现这个将字符串进行指定行数变换的函数：

```txt
string convert(string s, int numRows);
```

**示例 1：**

```txt
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
```

**示例 2：**
```txt
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
```

**示例 3：**

```txt
输入：s = "A", numRows = 1
输出："A"
```

**提示：**

- `1 <= s.length <= 1000`
- `s` 由英文字母（小写和大写）、`','` 和 `'.'` 组成
- `1 <= numRows <= 1000`

## 解析

使用一个数组存储每一行的字符串，在遍历过程中将每个字符拼接到数组对应行的字符串中。

## 代码

### C++

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows, "");
        bool down = false;
        for (int i = 0, row = 0; i < s.length(); i++) {
            rows[row] += s[i];
            if (row == 0 || row == numRows - 1) down = !down;
            row += down ? 1 : -1;
        }
        string ans = "";
        for (int i = 0; i < numRows; i++) ans += rows[i];
        return ans;
    }
};
```

### Go

```go
func convert(s string, numRows int) (ans string) {
    if numRows == 1 {
        ans = s
        return
    }
    rows := make([]string, numRows)
    row, down := 0, false
    for _, c := range s {
        rows[row] += string(c)
        if row == 0 || row == numRows-1 {
            down = !down
        }
        if down {
            row++
        } else {
            row--
        }
    }
    for i := range rows {
        ans += rows[i]
    }
    return
}
```

### Python

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = [""] * numRows
        i, row, down = 0, 0, False
        for i in range(len(s)):
            rows[row] += s[i]
            if row == 0 or row == numRows - 1:
                down = not down
            row += 1 if down else -1
        ans = ""
        for row in rows:
            ans += row
        return ans
```