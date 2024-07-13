# 24: 

# Given a linked list, swap every two adjacent nodes and return its head. 
# You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

# Solution: 

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
      dummy_node=ListNode(0)
      dummy_node.next=head
      previous_ptr=dummy_node
      current_ptr=head 

    while current_ptr and current_ptr.next:
      ptr_to_next_pair_starting=current_ptr.next.next
      ptr_after_current=current_ptr.next 

      ptr_after_current=current_ptr
      current_ptr.next=ptr_to_next_pair_starting 
      previous_ptr.next=ptr_after_current 

      previous_ptr=current_ptr
      current_ptr=ptr_to_next_pair_starting

    return dummy_node.next
