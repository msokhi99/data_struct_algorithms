# 83: 

# Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
# Return the linked list sorted as well.

# Solution: 

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
      temp_set=set()
      dummy_node=ListNode(next=head)
      prev=dummy_node
      curr=head 

    while curr:
      next=curr.next
      if curr.val in set:
        prev.next=next
        curr.next=None
      else:
        prev=prev.next
        temp_set.add(curr.val)
      curr=next
    return dummy_node.next
      
