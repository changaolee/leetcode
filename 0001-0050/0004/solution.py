from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1) + len(nums2)
        if n % 2 == 0:
            left = self.find(nums1, 0, nums2, 0, n // 2)
            right = self.find(nums1, 0, nums2, 0, n // 2 + 1)
            return (left + right) / 2
        else:
            return self.find(nums1, 0, nums2, 0, n // 2 + 1)

    def find(self, nums1, i, nums2, j, k):
        if len(nums1) - i > len(nums2) - j:
            return self.find(nums2, j, nums1, i, k)
        if len(nums1) == i:
            return nums2[j + k - 1]
        if k == 1:
            return min(nums1[i], nums2[j])

        si = min(len(nums1), i + k // 2)
        sj = j + k - k // 2
        if nums1[si - 1] < nums2[sj - 1]:
            return self.find(nums1, si, nums2, j, k - (si - i))
        else:
            return self.find(nums1, i, nums2, sj, k - (sj - j))


class Example:
    def __init__(self, nums1, nums2, ans):
        self.nums1 = nums1
        self.nums2 = nums2
        self.ans = ans


def main():
    examples = [
        Example([1, 3], [2], 2),
        Example([1, 2], [3, 4], 2.5),
    ]

    solve = Solution()
    for i, example in enumerate(examples):
        ans = solve.findMedianSortedArrays(example.nums1, example.nums2)
        if abs(ans - example.ans) <= 1e-8:
            print(f"PASS: CASE {i}")
        else:
            print(f"FAIL: CASE {i}")


if __name__ == "__main__":
    main()
