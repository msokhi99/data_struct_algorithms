# 11:

# You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
# Find two lines that together with the x-axis form a container, such that the container contains the most water.
# Return the maximum amount of water a container can store.
# Notice that you may not slant the container.

# Solution:

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left=0
        right=len(height)-1
        area=[]

        while left<right:
            width=abs(right-left)
            if height[left]>height[right]:
                length=height[right]
                right-=1
            else:
                length=height[left]
                left+=1
            result_area=length*width
            area.append(result_area)

        max_area=max(area)
        return max_area
