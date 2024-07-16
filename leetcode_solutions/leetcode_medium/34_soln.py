# 34: 

# Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
# If target is not found in the array, return [-1, -1].
# You must write an algorithm with O(log n) runtime complexity.

# Solution: 

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = []
        left = self.left_index(nums, target)
        right = self.right_index(nums, target)
        result.append(left)
        result.append(right)
        return result
    
    def left_index(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        index = -1

        while low <= high:
            middle = (low + high) // 2
            if nums[middle] == target:
                index = middle
                high = middle - 1
            elif nums[middle] > target:
                high = middle - 1
            else:
                low = middle + 1
        return index
    
    def right_index(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        index = -1

        while low <= high:
            middle = (low + high) // 2
            if nums[middle] == target:
                index = middle
                low = middle + 1
            elif nums[middle] > target:
                high = middle - 1
            else:
                low = middle + 1
        return index
