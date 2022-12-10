class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        pos = [-1] * 128
        ans = 0
        i, j = 0, 0
        while i < len(s):
            j = max(j, pos[ord(s[i])] + 1)
            ans = max(ans, i - j + 1)
            pos[ord(s[i])] = i
            i += 1
        return ans


class Example:
    def __init__(self, s, ans):
        self.s = s
        self.ans = ans


def main():
    examples = [
        Example("abcabcbb", 3),
        Example("bbbbb", 1),
        Example("pwwkew", 3)
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.lengthOfLongestSubstring(example.s)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
