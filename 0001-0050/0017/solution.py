from typing import List


class Solution:
    ans = []
    strs = [
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    ]

    def letterCombinations(self, digits: str) -> List[str]:
        self.ans = []
        if not digits:
            return self.ans
        self.dfs(digits, 0, "")
        return self.ans

    def dfs(self, digits, idx, combine):
        if idx == len(digits):
            self.ans.append(combine)
            return
        s = self.strs[int(digits[idx])]
        for i in range(len(s)):
            combine += s[i]
            self.dfs(digits, idx + 1, combine)
            combine = combine[:-1]


class Example:
    def __init__(self, digits, ans):
        self.digits = digits
        self.ans = ans


def main():
    examples = [
        Example("23", ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]),
        Example("", []),
        Example("2", ["a", "b", "c"])
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.letterCombinations(example.digits)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
