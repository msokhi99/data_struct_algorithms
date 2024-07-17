# 817: 

# You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
# Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

# Solution: 

class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:

      new_nums=set(nums)
      # Since, we have unique integer values, putting our list nums in a set will make our search faster.

      components=0

      while head:

        # Connected Components:
        if head and head.val in new_nums:
          while head and head.val in new_nums:
            head=head.next
          components+=1

        # Skipping the nodes that are not in new nums:
        elif head and head.val not in new_nums:
          while head and head.val not in new_nums:
            head=head.next

      return components
