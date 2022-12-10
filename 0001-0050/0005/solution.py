class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        for i in range(len(s)):
            # 奇数长度的回文串
            l, r = i - 1, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            if len(ans) < r - l - 1:
                ans = s[l + 1:r]

            # 偶数长度的回文串
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            if len(ans) < r - l - 1:
                ans = s[l + 1:r]
        return ans


class Example:
    def __init__(self, s, ans):
        self.s = s
        self.ans = ans


def main():
    examples = [
        Example("babad", "bab"),
        Example("cbbd", "bb"),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.longestPalindrome(example.s)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
