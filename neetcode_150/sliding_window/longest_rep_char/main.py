# Question:

# You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

# Return the length of the longest substring containing the same letter you can get after performing the above operations.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        hash_map={}
        longest_len=0
        left_window=0

        for right_window in range(len(s)):
            hash_map[s[right_window]]=1+hash_map.get(s[right_window],0)

            while (right_window-left_window+1)-max(hash_map.values())>k:
                hash_map[s[left_window]]-=1
                left_window+=1
            
            longest_len=max(longest_len,right_window-left_window+1)
        
        return longest_len
