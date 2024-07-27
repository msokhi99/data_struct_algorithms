# You are given an integer array heights where heights[i] represents the height of the ith bar.
# You may choose any two bars to form a container. Return the maximum amount of water a container can store.

# Solution:
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution:
  def container_water(self, nums: List[int]) -> int:
    left_ptr=0
    right_ptr=len(nums)-1
    area=[]

    while left_ptr<right_ptr:
      width=right_ptr-left_ptr
      if nums[left_ptr]>nums[right_ptr]:
        length=nums[right_ptr]
        right_ptr-=1
      else:
        length=nums[left_ptr]
        left_ptr+=1

      result=length*width
      area.append(result)

    return max(area)
