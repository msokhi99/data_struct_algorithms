# Solution:

# There is an integer array nums sorted in ascending order (with distinct values).

# Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is 
# [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

# Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

# You must write an algorithm with O(log n) runtime complexity.

# Solution:
# Time Complexity: O(log(n)).
# Space Complexity: O(1).

class Solution:
  def search_rotated_arr(self,nums:List[int],target:int)->int:
    result=self.rec_bin_search(nums,left_in=0,right_in=len(nums)-1,target=target)
    return result 
  def rec_bin_search(self,nums:List[int],left_in:int,right_in:int,target:int)->int:
    if left_in>right_in:
      return -1
    middle_in=(left_in+right_in)//2
    if nums[middle_in]==target:
      return middle_in
    if nums[left_in]<=nums[middle_in]:
      if nums[left_in]<=target<nums[middle_in]:
        return self.rec_bin_search(nums,left_in,middle_in-1,target)
      else:
        return self.rec_bin_search(nums,middle_in+1,right_in,target)
    else:
      if nums[middle_in]<=target<=nums[right_in]:
         return self.rec_bin_search(nums,middle_in+1,right_in,target)
      else:
         return self.rec_bin_search(nums,left_in,middle_in-1,target)
