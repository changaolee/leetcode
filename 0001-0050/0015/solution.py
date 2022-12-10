from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l, r = i + 1, len(nums) - 1
            target = 0 - nums[i]
            while l < r:
                if nums[l] + nums[r] == target:
                    ans.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif nums[l] + nums[r] < target:
                    l += 1
                else:
                    r -= 1
        return ans


class Example:
    def __init__(self, nums, ans):
        self.nums = nums
        self.ans = ans


def main():
    examples = [
        Example([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
        Example([0, 1, 1], []),
        Example([0, 0, 0], [[0, 0, 0]])
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.threeSum(example.nums)
        if ans == example.ans:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
