# Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
# You must write an algorithm that runs in O(n) time.

# Solution: Time Complexity: O(n): 

class Solution:
  def longest_seq(self, nums: List[int]) -> int:
    num_set=set(nums)
    longest_seq=0

    for num in nums:
      curr_len=1
      prev_num=num-1
      if prev_num not in num_set:
        next_num=num+1
        while next_num in num_set:
          curr_len+=1
          next_num+=1

      longest_seq=max(longest_seq,curr_len)

    return longest_seq
