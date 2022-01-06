"""
    Time Complexity: O(Nlog(N))
    Space Complexity: O(1)
"""

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        
        nums.sort()
        
        for i in range(1, len(nums) - 1, 2):
            nums[i] += nums[i + 1]
            nums[i + 1] = nums[i] - nums[i + 1]
            nums[i] -= nums[i + 1]
            
        