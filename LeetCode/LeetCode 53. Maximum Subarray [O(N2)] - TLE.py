class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        globalMaximum: int = -100000
         
            
        for startIndex in range(len(nums)):
            localMaximum: int = 0
                
            for num in nums[startIndex:]:
                localMaximum += num    
                globalMaximum = max(globalMaximum, localMaximum)
                
            
        return globalMaximum
