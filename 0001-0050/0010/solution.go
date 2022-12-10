package main

import (
    "fmt"
    "reflect"
)

func isMatch(s string, p string) bool {
    n, m := len(s), len(p)
    s = string(' ') + s
    p = string(' ') + p
    f := make([][]bool, n+1)
    for i := range f {
        f[i] = make([]bool, m+1)
    }
    f[0][0] = true
    for i := 0; i <= n; i++ {
        for j := 1; j <= m; j++ {
            if j+1 <= m && p[j+1] == '*' {
                continue
            }
            if p[j] != '*' {
                f[i][j] = i > 0 && j > 0 && f[i-1][j-1] && (s[i] == p[j] || p[j] == '.')
            } else {
                f[i][j] = (j >= 2 && f[i][j-2]) || (i > 0 && j > 0 && f[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.'))
            }
        }
    }
    return f[n][m]
}

type Example struct {
    s, p string
    ans  bool
}

func main() {
    examples := []Example{
        {"aa", "a", false},
        {"aa", "a*", true},
        {"ab", ".*", true},
    }
    for i, example := range examples {
        ans := isMatch(example.s, example.p)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
