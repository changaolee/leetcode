package main

import (
    "bytes"
    "fmt"
    "math"
    "reflect"
    "unicode"
)

func myAtoi(s string) (ans int) {
    rs := bytes.Runes([]byte(s))
    start := 0
    for start < len(rs) && rs[start] == ' ' {
        start++
    }
    if start == len(rs) {
        return
    }
    sign := 1
    if rs[start] == '-' {
        sign = -1
        start++
    } else if rs[start] == '+' {
        start++
    }
    for i := start; i < len(rs) && unicode.IsDigit(rs[i]); i++ {
        if sign > 0 && ans > (math.MaxInt32-int(rs[i]-'0'))/10 {
            ans = math.MaxInt32
            break
        }
        if sign < 0 && ans < (math.MinInt32+int(rs[i]-'0'))/10 {
            ans = math.MinInt32
            break
        }
        ans = ans*10 + sign*int(rs[i]-'0')
    }
    return
}

type Example struct {
    s   string
    ans int
}

func main() {
    examples := []Example{
        {"42", 42},
        {"   -42", -42},
        {"4193 with words", 4193},
    }
    for i, example := range examples {
        ans := myAtoi(example.s)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
