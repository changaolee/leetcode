package main

import (
    "fmt"
    "reflect"
)

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

type Example struct {
    s   string
    ans int
}

func main() {
    examples := []Example{
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
    }
    for i, example := range examples {
        ans := lengthOfLongestSubstring(example.s)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
