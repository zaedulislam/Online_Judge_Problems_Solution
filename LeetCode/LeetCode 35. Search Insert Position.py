class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low: int = 0
        high: int = len(nums) - 1
        mid: int = -1
            
        while low <= high:
            mid = (low + high) >> 1

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        
        return low