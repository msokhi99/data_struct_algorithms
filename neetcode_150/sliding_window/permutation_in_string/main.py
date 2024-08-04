# Question: 

# Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

# In other words, return true if one of s1's permutations is the substring of s2.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        '''Edge Case:'''
        if len(s1)>len(s2):
            return False 
        
        arr_one=[0]*26
        arr_two=[0]*26

        for i in range(len(s1)):
            arr_one[ord(s1[i])-ord('a')]+=1
            arr_two[ord(s2[i])-ord('a')]+=1
        
        char_matches=0
        for i in range(26):
            if arr_one[i]==arr_two[i]:
                char_matches+=1
        
        left_window=0
        for right_window in range(len(s1),len(s2)):

            if char_matches==26:
                return True

            index=ord(s2[right_window])-ord('a')
            arr_two[index]+=1

            if arr_one[index]==arr_two[index]:
                char_matches+=1
            elif arr_one[index]+1==arr_two[index]:
                char_matches-=1
            
            index=ord(s2[left_window])-ord('a')
            arr_two[index]-=1

            if arr_one[index]==arr_two[index]:
                char_matches+=1
            elif arr_one[index]-1==arr_two[index]:
                char_matches-=1
            
            left_window+=1
        
        return char_matches==26
