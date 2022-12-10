class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = [""] * numRows
        i, row, down = 0, 0, False
        for i in range(len(s)):
            rows[row] += s[i]
            if row == 0 or row == numRows - 1:
                down = not down
            row += 1 if down else -1
        ans = ""
        for row in rows:
            ans += row
        return ans


class Example:
    def __init__(self, s, numRows, ans):
        self.s = s
        self.numRows = numRows
        self.ans = ans


def main():
    examples = [
        Example("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
        Example("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
        Example("A", 1, "A")
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.convert(example.s, example.numRows)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
