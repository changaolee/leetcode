package main

import (
    "fmt"
    "reflect"
)

type ListNode struct {
    Val  int
    Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{Val: 0}
    cur := dummy
    for l1 != nil && l2 != nil {
        if l1.Val <= l2.Val {
            cur.Next = &ListNode{Val: l1.Val}
            l1 = l1.Next
        } else {
            cur.Next = &ListNode{Val: l2.Val}
            l2 = l2.Next
        }
        cur = cur.Next
    }
    if l1 != nil {
        cur.Next = l1
    } else {
        cur.Next = l2
    }
    return dummy.Next
}

type Example struct {
    l1, l2 *ListNode
    ans    *ListNode
}

func buildList(nums []int) *ListNode {
    dummy := &ListNode{Val: 0}
    cur := dummy
    for _, num := range nums {
        cur.Next = &ListNode{Val: num}
        cur = cur.Next
    }
    return dummy.Next
}

func main() {
    var examples []Example
    examples = append(examples, Example{
        l1:  buildList([]int{1, 2, 4}),
        l2:  buildList([]int{1, 3, 4}),
        ans: buildList([]int{1, 1, 2, 3, 4, 4}),
    })
    examples = append(examples, Example{
        l1:  buildList([]int{}),
        l2:  buildList([]int{}),
        ans: buildList([]int{}),
    })
    examples = append(examples, Example{
        l1:  buildList([]int{}),
        l2:  buildList([]int{0}),
        ans: buildList([]int{0}),
    })
    for i, example := range examples {
        ans := mergeTwoLists(example.l1, example.l2)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
