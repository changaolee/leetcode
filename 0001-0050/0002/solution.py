from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        cur = dummy
        sum = 0
        while l1 or l2 or sum:
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            cur.next = ListNode(sum % 10)
            cur = cur.next
            sum //= 10
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
        buildList([2, 4, 3]),
        buildList([5, 6, 4]),
        buildList([7, 0, 8])
    ), Example(
        buildList([0]),
        buildList([0]),
        buildList([0])
    ), Example(
        buildList([9, 9, 9, 9, 9, 9, 9]),
        buildList([9, 9, 9, 9]),
        buildList([8, 9, 9, 9, 0, 0, 0, 1])
    )]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.addTwoNumbers(example.l1, example.l2)
        if check(ans, example.ans):
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
