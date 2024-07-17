# 2807: 

# Given the head of a linked list head, in which each node contains an integer value.
# Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
# Return the linked list after insertion.
# The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

# Solution: 

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
      dummy_node=ListNode()
      dummy_node.next=head 
      p=head
      q=dummy_node

      while p and p.next:
        q=p
        p=p.next 
        gcd_val=self.find_gcd(q.val,p.val)
        new_node=ListNode()
        new_node.val=gcd_val
        q.next=new_node
        new_node.next=p

    def find_gcd(self,val_a,val_b):
      if val_b==0:
        return val_a
      else:
        return self.find_gcd(val_b,val_a % val_b)
