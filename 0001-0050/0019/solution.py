from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        slow, fast = dummy, dummy
        dummy.next = head
        for i in range(n):
            fast = fast.next
        while fast.next:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return dummy.next


class Example:
    def __init__(self, head, n, ans):
        self.head = head
        self.n = n
        self.ans = ans


def buildList(nums):
    dummy = ListNode(0)
    cur = dummy
    for num in nums:
        cur.next = ListNode(num)
        cur = cur.next
    return dummy.next


def check(l1, l2):
    p, q = l1, l2
    while p and q and p.val == q.val:
        p = p.next
        q = q.next
    return p == q


def main():
    examples = [Example(
        buildList([1, 2, 3, 4, 5]),
        2,
        buildList([1, 2, 3, 5])
    ), Example(
        buildList([1]),
        1,
        buildList([])
    ), Example(
        buildList([1, 2]),
        1,
        buildList([1])
    )]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.removeNthFromEnd(example.head, example.n)
        if check(ans, example.ans):
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
