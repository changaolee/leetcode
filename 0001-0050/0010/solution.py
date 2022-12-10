class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        s, p = ' ' + s, ' ' + p
        f = [[False] * (m + 1) for _ in range(n + 1)]
        f[0][0] = True
        for i in range(n + 1):
            for j in range(1, m + 1):
                if j + 1 <= m and p[j + 1] == '*':
                    continue
                if p[j] != '*':
                    f[i][j] = i and j and f[i - 1][j - 1] and (s[i] == p[j] or p[j] == '.')
                else:
                    f[i][j] = (j >= 2 and f[i][j - 2]) or (
                            i and j and f[i - 1][j] and (s[i] == p[j - 1] or p[j - 1] == '.'))
        return bool(f[n][m])


class Example:
    def __init__(self, s, p, ans):
        self.s = s
        self.p = p
        self.ans = ans


def main():
    examples = [
        Example("aa", "a", False),
        Example("aa", "a*", True),
        Example("ab", ".*", True),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.isMatch(example.s, example.p)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
