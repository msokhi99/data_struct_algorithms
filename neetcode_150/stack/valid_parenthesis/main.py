# You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

# The input string s is valid if and only if:

# Every open bracket is closed by the same type of close bracket.
# Open brackets are closed in the correct order.
# Every close bracket has a corresponding open bracket of the same type.
# Return true if s is a valid string, and false otherwise.

# Solution:

class Solution:
  def valid_or_not(self,s:str)->bool:
    hash_map={")":"(","}":"{","]":"["}
    temp_stack=[]

    for bracket in s:
      if bracket not in hash_map:
        temp_stack.append(bracket)
      else:
        if temp_stack or temp_stack[-1]!=hash_map[bracket]:
          return False
        temp_stack.pop()

    return not temp_stack
