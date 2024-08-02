# Question:

# Given a string s, find the length of the longest substring without repeating characters.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        temp_set=set()
        left_window=0
        max_seq=0

        for right_window in range(len(s)):
            while s[right_window] in temp_set:
                temp_set.remove(s[left_window])
                left_window+=1
            temp_set.add(s[right_window])
            max_seq=max(max_seq,right_window-left_window+1)
        
        return max_seq
