from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        for i in range(len(strs[0])):
            c = strs[0][i]
            for j in range(1, len(strs)):
                if i == len(strs[j]) or strs[j][i] != c:
                    return strs[0][:i]
        return strs[0]


class Example:
    def __init__(self, strs, ans):
        self.strs = strs
        self.ans = ans


def main():
    examples = [
        Example(["flower", "flow", "flight"], "fl"),
        Example(["dog", "racecar", "car"], "")
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.longestCommonPrefix(example.strs)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
