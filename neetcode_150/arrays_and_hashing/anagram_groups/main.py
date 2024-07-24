# Question: 

# Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

# Solution: 

class Solution:
  def anagram_groups(self, s: List[strs]) -> List[List[strs]]:
    hash_table={}

    for word in s:
      cano_form="".join(sorted(word))
      if cano_form in hash_table:
        hash_table[cano_form].append(word)
      else:
        hash_table[cano_form]=[word]

    return list(hash_table.values())

# Time Complexity: O(n * log(n)).
# Space Complexity: O(n).
    
