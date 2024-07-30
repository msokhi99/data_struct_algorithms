# 875: 

# Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

# Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
# If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

# Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

# Return the minimum integer k such that she can eat all the bananas within h hours.

# Solution:
# Time Complexity: O(n * log(n)).
# Space Complexity: O(1).

class Solution:
  def eating_rate(self,piles:List[int],h:int)->int:
    min_eating_speed=1
    max_eating_speed=max(piles)
    recom_speed=0

    while min_eating_speed<=max_eating_speed:
      mid_speed=(min_eating_speed+max_eating_speed)//2

      total_time=0
      for banana in piles:
        total_time+=math.ceil(float(banana)/mid_speed)

      if total_time<=h:
        recom_speed=mid_speed
        right_ptr=mid_speed-1
      else:
        left_ptr=mid_speed+1

    return recom_speed
