package main

import (
    "fmt"
    "reflect"
)

func maxArea(height []int) (ans int) {
    l, r := 0, len(height)-1
    for l < r {
        ans = max(ans, min(height[l], height[r])*(r-l))
        if height[l] < height[r] {
            l++
        } else {
            r--
        }
    }
    return
}

func max(x, y int) int {
    if x < y {
        return y
    }
    return x
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

type Example struct {
    height []int
    ans    int
}

func main() {
    examples := []Example{
        {[]int{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
        {[]int{1, 1}, 1},
    }
    for i, example := range examples {
        ans := maxArea(example.height)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
