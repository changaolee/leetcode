class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MIN, INT_MAX = -2 ** 31, 2 ** 31 - 1
        ans = 0

        # 去除前导空格
        start = 0
        while start < len(s) and s[start] == ' ':
            start += 1
        if start == len(s):
            return 0

        # 判断正负号
        sign = 1
        if s[start] == '-':
            sign = -1
            start += 1
        elif s[start] == '+':
            start += 1

        # 读取数字
        for i in range(start, len(s)):
            if not str.isdigit(s[i]):
                break
            ans = ans * 10 + sign * int(s[i])
            if ans > 0 and ans >= INT_MAX:
                return INT_MAX
            if ans < 0 and ans <= INT_MIN:
                return INT_MIN

        return ans


class Example:
    def __init__(self, s, ans):
        self.s = s
        self.ans = ans


def main():
    examples = [
        Example("42", 42),
        Example("   -42", -42),
        Example("4193 with words", 4193),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.myAtoi(example.s)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
