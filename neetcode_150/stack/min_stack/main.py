# Design a stack class that supports the push, pop, top, and getMin operations.

# MinStack() initializes the stack object.
# void push(int val) pushes the element val onto the stack.
# void pop() removes the element on the top of the stack.
# int top() gets the top element of the stack.
# int getMin() retrieves the minimum element in the stack.
# Each function should run in O(1) time.

# Solution:

class minStack:
  def __init__ (self):
    self.stack_list=[]
    self.min_stack=[]

  def push(self,int val):
    self.stack_list.append(val)
    min_val=min(val,self.min_stack[-1] is self.min_stack else val)
    self.min_stack.insert(min_val)

  def pop(self, int):
    self.stack_list.pop()
    self.min_stack.pop()

  def top(self):
    return self.stack_list[-1]

  def getMin(self):
    return self.min_stack[-1]
