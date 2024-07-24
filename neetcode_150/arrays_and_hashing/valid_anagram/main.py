# Question: 

# Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

# Solution: 

class Solution:
  def valid_anagram(self, s: str, t: str) -> bool:
    sorted_string_s="".join(sorted(s))
    sorted_string_t="".join(sorted(t))

    if sorted_string_s==sorted_string_t:
      return True
    else:
      return False 

# Time Complexity: O(n * log(n)).
# Space Complexity: O(n).
