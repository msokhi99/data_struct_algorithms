# 21: 

# You are given the heads of two sorted linked lists list1 and list2.
# Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
# Return the head of the merged linked list.

# Solution: 

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
      dummy_node=ListNode()
      last_val_ptr=dummy_node

    while list1 and list2:
      if list1.val<list2.val:
        last_val_ptr.next=list1
        list1=list1.next
      else:
        last_val_ptr.next=list2
        list2=list2.next
      last_val_ptr=last_val_ptr.next 

    if list1:
      last_val_ptr.next=list1
    elif list2:
      last_val_ptr.next=list2

    return dummy_node.next
