class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2 ** 31, 2 ** 31 - 1
        ans = 0
        while x:
            digit = x % 10
            if x < 0 and digit > 0:
                digit -= 10
            if x > 0 and ans > (INT_MAX - digit) // 10:
                return 0
            if x < 0 and ans < -((INT_MIN - digit) // -10):
                return 0
            ans = ans * 10 + digit
            x = x // 10 if x > 0 else -(x // -10)
        return ans


class Example:
    def __init__(self, x, ans):
        self.x = x
        self.ans = ans


def main():
    examples = [
        Example(123, 321),
        Example(-123, -321),
        Example(120, 21),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.reverse(example.x)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
