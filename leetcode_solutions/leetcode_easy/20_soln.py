# 20: 

# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# Solution: 

class Solution:
    def isValid(self, s: str) -> bool:
      stack=[]
      temp_dict={")":"(","]":"[","}":"{"}

      for char in s:
        if char in temp_dict:
          if stack and stack[-1]==temp_dict[char]:
            stack.pop()
          else:
            return False
        else:
          stack.append(char)

      return True if not stack else False
          
