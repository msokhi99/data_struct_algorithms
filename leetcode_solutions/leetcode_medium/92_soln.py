# 92: 

# Given the head of a singly linked list and two integers left and right where left <= right, 
# reverse the nodes of the list from position left to position right, and return the reversed list.

# Solution: 

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
      dummy_node=ListNode(0,head)
      left_prev=dummy_node
      curr=head

    for _ in range(left-1):
      left_prev=curr
      curr=curr.next

    prev=None
    for _ in range(right - left + 1):
      temp_curr_next=curr.next
      curr.next=prev
      prev=curr
      curr=temp_curr_next

    left_prev.next.next=curr
    left_prev.next=prev
    return dummy_node.next
