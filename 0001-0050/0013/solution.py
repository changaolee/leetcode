class Solution:
    def romanToInt(self, s: str) -> int:
        value = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000,
        }
        ans = 0
        for i in range(len(s)):
            if i + 1 < len(s) and value[s[i]] < value[s[i + 1]]:
                ans -= value[s[i]]
            else:
                ans += value[s[i]]
        return ans


class Example:
    def __init__(self, s, ans):
        self.s = s
        self.ans = ans


def main():
    examples = [
        Example("III", 3),
        Example("LVIII", 58),
        Example("MCMXCIV", 1994)
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.romanToInt(example.s)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
