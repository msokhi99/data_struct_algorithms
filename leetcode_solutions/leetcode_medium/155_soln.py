# 155:

# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

# Implement the MinStack class:

# MinStack() initializes the stack object.
# void push(int val) pushes the element val onto the stack.
# void pop() removes the element on the top of the stack.
# int top() gets the top element of the stack.
# int getMin() retrieves the minimum element in the stack.
# You must implement a solution with O(1) time complexity for each function.

# Solution: 

class min_stack:
  def __init__ (self):
    self.stack_list=[]
    self.min_stack=[]

  def push (self, val): 
    self.stack_list.append(val)
    min_val=min(val,self.min_stack[-1] if self.min_stack else val)
    self.min_stack.append(min_val)

  def pop (self):
    self.stack_list.pop()
    self.min_stack.pop()

  def top (self):
    return self.stack_list[-1]

  def get_min (self):
    return self.min_stack[-1]
