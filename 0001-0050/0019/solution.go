package main

import (
    "fmt"
    "reflect"
)

type ListNode struct {
    Val  int
    Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    dummy := &ListNode{Val: 0}
    slow, fast := dummy, dummy
    dummy.Next = head
    for i := 0; i < n; i++ {
        fast = fast.Next
    }
    for fast.Next != nil {
        slow = slow.Next
        fast = fast.Next
    }
    slow.Next = slow.Next.Next
    return dummy.Next
}

type Example struct {
    head *ListNode
    n    int
    ans  *ListNode
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
        head: buildList([]int{1, 2, 3, 4, 5}),
        n:    2,
        ans:  buildList([]int{1, 2, 3, 5}),
    })
    examples = append(examples, Example{
        head: buildList([]int{1}),
        n:    1,
        ans:  buildList([]int{}),
    })
    examples = append(examples, Example{
        head: buildList([]int{1, 2}),
        n:    1,
        ans:  buildList([]int{1}),
    })
    for i, example := range examples {
        ans := removeNthFromEnd(example.head, example.n)
        if reflect.DeepEqual(ans, example.ans) {
            fmt.Printf("PASS: CASE %d\n", i)
        } else {
            fmt.Printf("FAIL: CASE %d\n", i)
        }
    }
}
