from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        l, r = 0, len(height) - 1
        while l < r:
            ans = max(ans, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans


class Example:
    def __init__(self, height, ans):
        self.height = height
        self.ans = ans


def main():
    examples = [
        Example([1, 8, 6, 2, 5, 4, 8, 3, 7], 49),
        Example([1, 1], 1),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.maxArea(example.height)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
