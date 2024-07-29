# Question:

# You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

# Evaluate the expression. Return an integer that represents the value of the expression.

# Note that:

# The valid operators are '+', '-', '*', and '/'.
# Each operand may be an integer or another expression.
# The division between two integers always truncates toward zero.
# There will not be any division by zero.
# The input represents a valid arithmetic expression in a reverse polish notation.
# The answer and all the intermediate calculations can be represented in a 32-bit integer.

# Solution:
# Time Complexity: O(n).
# Space Complexity: O(n).

class Solution:
  def eval_rpn (self,tokens: List[str])->int:
    stack_list=[]

    for token in tokens:
      if token == "+":
        stack_list.append(stack_list.pop() + stack_list.pop())
      elif token == "-":
        num_one=stack_list.pop()
        num_two=stack_list.pop()
        stack_list.append(num_two - num_one)
      elif token == "*":
        stack_list.append(stack_list.pop() * stack_list.pop())
      elif token == "/":
        num_one=stack_list.pop()
        num_two=stack_list.pop()
        stack_list.append(int(float(num_two))/num_one)
      else:
        stack_list.append(int(token))

    return stack_list[0]
