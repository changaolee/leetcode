package main

import (
    "fmt"
    "reflect"
)

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

type Example struct {
    s       string
    numRows int
    ans     string
}

func main() {
    examples := []Example{
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"A", 1, "A"},
    }
    for i, example := range examples {
        ans := convert(example.s, example.numRows)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
