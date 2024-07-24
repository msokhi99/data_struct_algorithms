# 49: 

# Given an array of strings strs, group the anagrams together. You can return the answer in any order.

# Solution: 

class Solution:
  def countAnagrams(self, strs: List[strings]) -> List[List[strings]]:
    hash_table={}

    # Loop through each word in the input list:

    for word in strs:

      # Sort the letters of the word:
      cano_form="".join(sorted(word))

      # Now, we check if this sorted word is in the hash table. If it is, then we just append
      # the word to the key. Else, we add this cano form as a key in the hash table.

      if cano_form in hash_table:
        hash_table[cano_form].append(word)
      else:
        hash_table[cano_form]=[word]

    return list(hash_table.values())
