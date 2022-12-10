package main

import (
    "fmt"
    "reflect"
)

func romanToInt(s string) (ans int) {
    value := map[byte]int{
        'I': 1, 'V': 5, 'X': 10, 'L': 50,
        'C': 100, 'D': 500, 'M': 1000,
    }
    for i := 0; i < len(s); i++ {
        if i+1 < len(s) && value[s[i]] < value[s[i+1]] {
            ans -= value[s[i]]
        } else {
            ans += value[s[i]]
        }
    }
    return
}

type Example struct {
    s   string
    ans int
}

func main() {
    examples := []Example{
        {"III", 3},
        {"LVIII", 58},
        {"MCMXCIV", 1994},
    }
    for i, example := range examples {
        ans := romanToInt(example.s)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
