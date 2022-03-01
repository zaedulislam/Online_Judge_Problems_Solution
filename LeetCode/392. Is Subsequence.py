class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        sIndex: int = 0
        
        for tChar in t:
            if(sIndex == len(s)):
                return True
            elif(tChar == s[sIndex]):
                sIndex += 1
        
        return sIndex == len(s)
