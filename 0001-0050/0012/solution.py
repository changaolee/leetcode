class Solution:
    def intToRoman(self, num: int) -> str:
        thousands = ["", "M", "MM", "MMM"]
        hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        return thousands[num // 1000] + hundreds[num % 1000 // 100] + tens[num % 100 // 10] + ones[num % 10]


class Example:
    def __init__(self, num, ans):
        self.num = num
        self.ans = ans


def main():
    examples = [
        Example(3, "III"),
        Example(58, "LVIII"),
        Example(1994, "MCMXCIV")
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.intToRoman(example.num)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
