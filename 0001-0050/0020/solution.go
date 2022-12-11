package main

import (
    "fmt"
    "reflect"
)

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

type Example struct {
    s   string
    ans bool
}

func main() {
    examples := []Example{
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
    }
    for i, example := range examples {
        ans := isValid(example.s)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
