package main

import (
    "fmt"
    "reflect"
)

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

type Example struct {
    digits string
    ans    []string
}

func main() {
    examples := []Example{
        {"23", []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        {"", []string{}},
        {"2", []string{"a", "b", "c"}},
    }
    for i, example := range examples {
        ans := letterCombinations(example.digits)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
