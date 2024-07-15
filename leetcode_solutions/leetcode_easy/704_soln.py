# 704: 

# Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
# If target exists, then return its index. Otherwise, return -1.
# You must write an algorithm with O(log n) runtime complexity.

# Solution: 

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1

        while low<=high:
            middle=(high+low) // 2
            if nums[middle]==target:
                return middle
            elif nums[middle]>target:
                high=middle-1
            else:
                low=low+1
        
        return -1
