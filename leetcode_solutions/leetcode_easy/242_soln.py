# 242: 

# Given two strings s and t, return true if t is an anagram of s, and false otherwise.

# Solution: 

class Solution:
  def valid_anagram(self, s: str, t: str) -> bool:
    sorted_string_s="".join(sorted(s))
    sorted_string_t="".join(sorted(t))

    if sorted_string_s==sorted_string_t:
      return True
    else:
      return False

# Time Complexity: O(log(n)).
