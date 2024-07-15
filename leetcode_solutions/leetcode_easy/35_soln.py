# 35: 

# Given a sorted array of distinct integers and a target value, return the index if the target is found. 
# If not, return the index where it would be if it were inserted in order.
# You must write an algorithm with O(log n) runtime complexity.

# Solution: 

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
      low=0
      high=len(nums)-1

      while low<=high:
        middle=low + (high-low) // 2
        if nums[middle]==target:
          return middle
        elif nums[middle]>target:
          high=middle-1
        else:
          low=middle+1

      return low
