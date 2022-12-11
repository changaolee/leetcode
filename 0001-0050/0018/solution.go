package main

import (
    "fmt"
    "reflect"
    "sort"
)

func fourSum(nums []int, target int) (ans [][]int) {
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        for j := i + 1; j < len(nums); j++ {
            if j > i+1 && nums[j] == nums[j-1] {
                continue
            }
            l, r := j+1, len(nums)-1
            sum := target - nums[i] - nums[j]
            for l < r {
                if nums[l]+nums[r] == sum {
                    ans = append(ans, []int{nums[i], nums[j], nums[l], nums[r]})
                    for l < r && nums[l] == nums[l+1] {
                        l++
                    }
                    for l < r && nums[r] == nums[r-1] {
                        r--
                    }
                    l++
                    r--
                } else if nums[l]+nums[r] < sum {
                    l++
                } else {
                    r--
                }
            }
        }
    }
    return
}

type Example struct {
    nums   []int
    target int
    ans    [][]int
}

func main() {
    examples := []Example{
        {[]int{1, 0, -1, 0, -2, 2}, 0, [][]int{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}},
        {[]int{2, 2, 2, 2, 2}, 8, [][]int{{2, 2, 2, 2}}},
    }
    for i, example := range examples {
        ans := fourSum(example.nums, example.target)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
