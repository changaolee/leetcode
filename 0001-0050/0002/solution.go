package main

import (
    "fmt"
    "reflect"
)

type ListNode struct {
    Val  int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) (ans *ListNode) {
    cur, sum := ans, 0
    for l1 != nil || l2 != nil || sum != 0 {
        if l1 != nil {
            sum += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            sum += l2.Val
            l2 = l2.Next
        }
        if ans == nil {
            ans = &ListNode{Val: sum % 10}
            cur = ans
        } else {
            cur.Next = &ListNode{Val: sum % 10}
            cur = cur.Next
        }
        sum = sum / 10
    }
    return
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
        l1:  buildList([]int{2, 4, 3}),
        l2:  buildList([]int{5, 6, 4}),
        ans: buildList([]int{7, 0, 8}),
    })
    examples = append(examples, Example{
        l1:  buildList([]int{0}),
        l2:  buildList([]int{0}),
        ans: buildList([]int{0}),
    })
    examples = append(examples, Example{
        l1:  buildList([]int{9, 9, 9, 9, 9, 9, 9}),
        l2:  buildList([]int{9, 9, 9, 9}),
        ans: buildList([]int{8, 9, 9, 9, 0, 0, 0, 1}),
    })
    for i, example := range examples {
        ans := addTwoNumbers(example.l1, example.l2)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
