# 599:

# Given two arrays of strings list1 and list2, find the common strings with the least index sum.
# A common string is a string that appeared in both list1 and list2.
# A common string with the least index sum is a common string such that if it appeared at 
# list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.
# Return all the common strings with the least index sum. Return the answer in any order.

# Solution: 

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        output_list=[]
        min=0

        for i in range(len(list1)):
            for j in range(len(list2)):
                if list1[i]==list2[j]:
                    if not output_list:
                        output_list.append(list1[i])
                        min=i+j
                    elif i+j==min:
                        output_list.append(list1[i])
                    elif i+j<min:
                        output_list.pop()
                        output_list.append(list1[i])
        
        return output_list
