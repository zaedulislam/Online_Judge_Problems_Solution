class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        low: int = 1
        high: int = num
        
        while low <= high:
            mid: int = int((low + high) >> 1)
            
            square: int = mid * mid
            
            if square == num:
                return True
            elif square > num:
                high = mid - 1
            else:
                low = mid + 1
        
        return False
            