from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        record = {}
        for i, num in enumerate(nums):
            x = target - num
            if x in record:
                return [record[x], i]
            record[num] = i
        return [-1, -1]


class Example:
    def __init__(self, nums, target, ans):
        self.nums = nums
        self.target = target
        self.ans = ans


def main():
    examples = [
        Example([2, 7, 11, 15], 9, [0, 1]),
        Example([3, 2, 4], 6, [1, 2]),
        Example([3, 3], 6, [0, 1]),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.twoSum(example.nums, example.target)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
