"""
    Time Complexity: O(nlogn) 
    Space Complexity: O(logn) to O(n) depending on the implementation of the sorting algorithm.
"""

class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        
        nums.sort()
        
        left: int = 0
        right: int = len(nums) - 1
        maximumSum: int = -1
        
        while left < right:
            currentSum: int = nums[left] + nums[right]
            
            if currentSum < k:
                maximumSum = max(maximumSum, currentSum)
                left += 1
            elif currentSum >= k:
                right -= 1
                        
        return maximumSum