package main

import (
    "fmt"
    "reflect"
    "sort"
)

func threeSum(nums []int) (ans [][]int) {
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        l, r := i+1, len(nums)-1
        target := 0 - nums[i]
        for l < r {
            if nums[l]+nums[r] == target {
                ans = append(ans, []int{nums[i], nums[l], nums[r]})
                for l < r && nums[l] == nums[l+1] {
                    l++
                }
                for l < r && nums[r] == nums[r-1] {
                    r--
                }
                l++
                r--
            } else if nums[l]+nums[r] < target {
                l++
            } else {
                r--
            }
        }
    }
    return
}

type Example struct {
    nums []int
    ans  [][]int
}

func main() {
    examples := []Example{
        {[]int{-1, 0, 1, 2, -1, -4}, [][]int{{-1, -1, 2}, {-1, 0, 1}}},
        {nums: []int{0, 1, 1}},
        {[]int{0, 0, 0}, [][]int{{0, 0, 0}}},
    }
    for i, example := range examples {
        ans := threeSum(example.nums)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
