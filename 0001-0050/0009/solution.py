class Solution:
    def isPalindrome(self, x: int) -> bool:
        INT_MAX = 2 ** 31 - 1
        if x < 0:
            return False
        num, cur = x, 0
        while x:
            if cur > (INT_MAX - x % 10) // 10:
                return False
            cur = cur * 10 + x % 10
            x //= 10
        return cur == num


class Example:
    def __init__(self, x, ans):
        self.x = x
        self.ans = ans


def main():
    examples = [
        Example(121, True),
        Example(-121, False),
        Example(10, False),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.isPalindrome(example.x)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
