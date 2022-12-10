package main

import (
    "fmt"
    "math"
    "reflect"
)

func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }
    num, cur := x, 0
    for x != 0 {
        if cur > (math.MaxInt32-x%10)/10 {
            return false
        }
        cur = cur*10 + x%10
        x /= 10
    }
    return num == cur
}

type Example struct {
    x   int
    ans bool
}

func main() {
    examples := []Example{
        {121, true},
        {-121, false},
        {10, false},
    }
    for i, example := range examples {
        ans := isPalindrome(example.x)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
