package main

import (
    "fmt"
    "reflect"
)

func twoSum(nums []int, target int) (ans []int) {
    record := map[int]int{}
    for i, num := range nums {
        if p, ok := record[target-num]; ok {
            return []int{p, i}
        }
        record[num] = i
    }
    return nil
}

type Example struct {
    nums   []int
    target int
    ans    []int
}

func main() {
    examples := []Example{
        {[]int{2, 7, 11, 15}, 9, []int{0, 1}},
        {[]int{3, 2, 4}, 6, []int{1, 2}},
        {[]int{3, 3}, 6, []int{0, 1}},
    }
    for i, example := range examples {
        ans := twoSum(example.nums, example.target)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
