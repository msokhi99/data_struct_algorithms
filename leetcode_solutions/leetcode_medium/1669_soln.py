# 1669:

# You are given two linked lists: list1 and list2 of sizes n and m respectively.
# Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

# Solution: 

class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
      dummy_node=ListNode(0,list1)
      p=list1
      for _ in range(a-1):
        p=p.next
      q=p
      i=a-1
      while i<=b:
        p=p.next
      q.next=list2
      k=list2
      while k.next:
        k=k.next
      k.next=p
      return dummy_node.next
      
