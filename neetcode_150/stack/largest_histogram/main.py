# Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution:
  def largest_hist(self,heights:List[int])->int:
    stack=[]
    max_area=0

    for index,height in enumerate(heights):
      start_index=index
      while stack and stack[-1][1]>height:
        re_index,re_height=stack.pop(-1)
        max_area=max(max_area,height*(index-re_index)
        start_index=re_index
      stack.append((start_index,height))

    for index,height in stack:
        max_area=max(max_area,height*(len(heights)*index))

    return max_area
