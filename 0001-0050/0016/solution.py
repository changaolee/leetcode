from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = nums[0] + nums[1] + nums[2]
        nums.sort()
        for i in range(len(nums)):
            l, r = i + 1, len(nums) - 1
            while l < r:
                _sum = nums[i] + nums[l] + nums[r]
                if _sum == target:
                    return _sum
                if abs(_sum - target) < abs(ans - target):
                    ans = _sum
                if _sum < target:
                    l += 1
                else:
                    r -= 1
        return ans


class Example:
    def __init__(self, nums, target, ans):
        self.nums = nums
        self.target = target
        self.ans = ans


def main():
    examples = [
        Example([-1, 2, 1, -4], 1, 2),
        Example([0, 0, 0], 1, 0)
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.threeSumClosest(example.nums, example.target)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
