# Question: 

# Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

# [4,5,6,7,0,1,2] if it was rotated 4 times.
# [0,1,2,4,5,6,7] if it was rotated 7 times.
# Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

# Given the sorted rotated array nums of unique elements, return the minimum element of this array.

# You must write an algorithm that runs in O(log n) time.

# Solution: 
# Time Complexity: O(log(n)).
# Space Complexity: O(1).

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left_ptr=0
        right_ptr=len(nums)-1
        min_val=nums[0]

        while left_ptr<=right_ptr:
            if nums[left_ptr]<nums[right_ptr]:
                min_val=min(min_val,nums[left_ptr])
            
            middle_ptr=(left_ptr+right_ptr)//2
            min_val=min(min_val,nums[middle_ptr])

            if nums[middle_ptr]>=nums[left_ptr]:
                left_ptr=middle_ptr+1
            else:
                right_ptr=middle_ptr-1
        
        return min_val
