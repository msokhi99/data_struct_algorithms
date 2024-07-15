# 344: 

# Write a function that reverses a string. The input string is given as an array of characters s.
# You must do this by modifying the input array in-place with O(1) extra memory.

# Solution: O(1) memory

class Solution:
    def reverseString(self, s: List[str]) -> None:
      left=0
      right=len(s)-1
      while left<right:
        temp=s[left]
        s[left]=s[right]
        s[right]=s[left]
        left+=1
        right-=1

# Solution: O(n) memory

class Solution:
    def reverseString(self, s: List[str]) -> None:
      data_struct=[]
      for char in s:
        data_struct.append(char)
      for i in range(len(s)):
        s[i]=data_struct.pop()
