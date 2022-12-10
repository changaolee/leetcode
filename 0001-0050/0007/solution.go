package main

import (
    "fmt"
    "math"
    "reflect"
)

func reverse(x int) (ans int) {
    for x != 0 {
        if x > 0 && ans > (math.MaxInt32-x%10)/10 {
            return 0
        }
        if x < 0 && ans < (math.MinInt32-x%10)/10 {
            return 0
        }
        ans = ans*10 + x%10
        x /= 10
    }
    return
}

type Example struct {
    x   int
    ans int
}

func main() {
    examples := []Example{
        {123, 321},
        {-123, -321},
        {120, 21},
    }
    for i, example := range examples {
        ans := reverse(example.x)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
