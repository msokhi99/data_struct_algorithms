# 42: 

# Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(1). 

class Solution:
  def rain_water_trap(self, nums: List[int]) -> int:
    left_ptr=0
    right_ptr=len(nums)-1
    max_h_left=height[left_ptr]
    max_h_right=height[right_ptr]
    trapped_rain=0
    
    while left_ptr<right_ptr:
      if max_h_left<max_h_right:
        left_ptr+=1
        max_h_left=max(max_h_left,nums[left_ptr])
        trapped_rain+=max_h_left-nums[left_ptr]
      else:
        right_ptr-=1
        max_h_right=max(max_h_right,nums[right_ptr])
        trapped_rain+=max_h_right-nums[right_ptr]

    return trapped_rain
