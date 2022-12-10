package main

import (
    "fmt"
    "reflect"
)

func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    for i := 0; i < len(strs[0]); i++ {
        c := strs[0][i]
        for j := 1; j < len(strs); j++ {
            if i == len(strs[j]) || strs[j][i] != c {
                return strs[0][:i]
            }
        }
    }
    return strs[0]
}

type Example struct {
    strs []string
    ans  string
}

func main() {
    examples := []Example{
        {[]string{"flower", "flow", "flight"}, "fl"},
        {[]string{"dog", "racecar", "car"}, ""},
    }
    for i, example := range examples {
        ans := longestCommonPrefix(example.strs)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
