# 121: 

# You are given an array prices where prices[i] is the price of a given stock on the ith day.

# You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

# Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

# Solution: 
# Time Complexity: O(n).
# Space Complexity: O(1). 

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left_ptr=0
        right_ptr=1
        max_profit=0

        while right_ptr<len(prices):
            if prices[left_ptr]<prices[right_ptr]:
                profit=prices[right_ptr]-prices[left_ptr]
                max_profit=max(max_profit,profit)
            else:
                left_ptr=right_ptr
            right_ptr+=1
        
        return max_profit
