package main

import (
    "fmt"
    "reflect"
    "sort"
)

func threeSumClosest(nums []int, target int) int {
    ans := nums[0] + nums[1] + nums[2]
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        l, r := i+1, len(nums)-1
        for l < r {
            sum := nums[i] + nums[l] + nums[r]
            if sum == target {
                return sum
            }
            if abs(sum-target) < abs(ans-target) {
                ans = sum
            }
            if sum < target {
                l++
            } else {
                r--
            }
        }
    }
    return ans
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

type Example struct {
    nums   []int
    target int
    ans    int
}

func main() {
    examples := []Example{
        {[]int{-1, 2, 1, -4}, 1, 2},
        {[]int{0, 0, 0}, 1, 0},
    }
    for i, example := range examples {
        ans := threeSumClosest(example.nums, example.target)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
