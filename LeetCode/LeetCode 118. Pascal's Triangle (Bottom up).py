'''
    Time complexity: O(numRows^2)
    Space complexity: O(numRows^2)
'''

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascalsTriange: List[List[int]] = []
        
        for rowNumber in range(numRows):
            currentRow = [None for _ in range(rowNumber + 1)]
            currentRow[0], currentRow[-1] = 1, 1
            
            for index in range(1, len(currentRow) - 1):
                currentRow[index] = pascalsTriange[rowNumber - 1][index - 1] + pascalsTriange[rowNumber - 1][index]

            pascalsTriange.append(currentRow)
            
        return pascalsTriange