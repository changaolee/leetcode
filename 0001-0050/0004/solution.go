package main

import (
    "fmt"
    "math"
)

func findMedianSortedArrays(x []int, y []int) (ans float64) {
    n := len(x) + len(y)
    if n%2 == 0 {
        left := find(x, 0, y, 0, n/2)
        right := find(x, 0, y, 0, n/2+1)
        ans = float64(left+right) / 2.0
    } else {
        ans = find(x, 0, y, 0, n/2+1)
    }
    return
}

func find(x []int, i int, y []int, j int, k int) float64 {
    if len(x)-i > len(y)-j {
        return find(y, j, x, i, k)
    }
    if len(x)-i == 0 {
        return float64(y[j+k-1])
    }
    if k == 1 {
        return float64(min(x[i], y[j]))
    }
    si := min(len(x), i+k/2)
    sj := j + k - k/2
    if x[si-1] < y[sj-1] {
        return find(x, si, y, j, k-(si-i))
    } else {
        return find(x, i, y, sj, k-(sj-j))
    }
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

type Example struct {
    nums1, num2 []int
    ans         float64
}

func main() {
    examples := []Example{
        {[]int{1, 3}, []int{2}, 2.},
        {[]int{1, 2}, []int{3, 4}, 2.5},
    }
    for i, example := range examples {
        ans := findMedianSortedArrays(example.nums1, example.num2)
        if math.Abs(ans-example.ans) <= 1e-8 {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
