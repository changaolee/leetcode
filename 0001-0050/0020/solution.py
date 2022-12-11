class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {
            '(': ')', '{': '}', '[': ']'
        }
        stk = []
        for i in range(len(s)):
            if s[i] in pairs:
                stk.append(pairs[s[i]])
            else:
                if not stk or stk[-1] != s[i]:
                    return False
                stk = stk[:-1]
        return not stk


class Example:
    def __init__(self, s, ans):
        self.s = s
        self.ans = ans


def main():
    examples = [
        Example("()", True),
        Example("()[]{}", True),
        Example("(]", False)
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.isValid(example.s)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
