from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums)):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                l, r = j + 1, len(nums) - 1
                _sum = target - nums[i] - nums[j]
                while l < r:
                    if nums[l] + nums[r] == _sum:
                        ans.append([nums[i], nums[j], nums[l], nums[r]])
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        l += 1
                        r -= 1
                    elif nums[l] + nums[r] < _sum:
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
        Example([1, 0, -1, 0, -2, 2], 0, [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]),
        Example([2, 2, 2, 2, 2], 8, [[2, 2, 2, 2]])
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.fourSum(example.nums, example.target)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
