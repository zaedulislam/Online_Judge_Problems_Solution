"""
    Time Complexity: O(N)
    Space Complexity: O(1)
"""

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        
        for index in range(len(nums) - 1):
            if((not(index & 1) and (nums[index] > nums[index + 1]))
               or ((index & 1) and (nums[index] < nums[index + 1]))):
                nums[index] += nums[index + 1]
                nums[index + 1] = nums[index] - nums[index + 1]
                nums[index] -= nums[index + 1]
               
            
        