# Given a string s, return true if it is a palindrome, otherwise return false.
# A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

# Solution:
# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
  def isPalindrome(self,s:str)->bool:
    s=" ".join(ch for ch in s if s.isalnum()).lower().split(" ")

    left_ptr=0
    right_ptr=len(s)-1

    while left_ptr<=right_ptr:
      if s[left_ptr]!=s[right_ptr]:
        return False
      left_ptr+=1
      right_ptr-=1

    return True

# Solution 2: Faster runtime.
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
  def isPalindrome(self,s:str)->bool:
    left_ptr=0
    right_ptr=len(s)-1

    while left_ptr<=right_ptr:
      while left_ptr<right_ptr and not s[left_ptr].isalnum():
        left_ptr+=1
      while right_ptr>left_ptr and not s[right_ptr].isalnum():
        right_ptr-=1

      if s[left_ptr].lower() !=s[right_ptr].lower():
        return False 
      left_ptr+=1
      right_ptr-=1

    return True
