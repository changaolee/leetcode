from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        cur = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = ListNode(l1.val)
                l1 = l1.next
            else:
                cur.next = ListNode(l2.val)
                l2 = l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        return dummy.next


class Example:
    def __init__(self, l1, l2, ans):
        self.l1 = l1
        self.l2 = l2
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
        buildList([1, 2, 4]),
        buildList([1, 3, 4]),
        buildList([1, 1, 2, 3, 4, 4])
    ), Example(
        buildList([]),
        buildList([]),
        buildList([])
    ), Example(
        buildList([]),
        buildList([0]),
        buildList([0])
    )]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.mergeTwoLists(example.l1, example.l2)
        if check(ans, example.ans):
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
