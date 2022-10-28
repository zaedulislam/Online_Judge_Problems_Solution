class Solution {
public:
    static void traverseGrid(int x, int y, int numberOfRows, int numberOfColumns, vector<vector<char>>& grid){
        
        grid[x][y] = '0';
        
        if(x - 1 >= 0 && grid[x - 1][y] == '1'){
            traverseGrid(x - 1, y, numberOfRows, numberOfColumns, grid);
        }
        
        if(x + 1 < numberOfRows && grid[x + 1][y] == '1'){
            traverseGrid(x + 1, y, numberOfRows, numberOfColumns, grid);
        }
        
        if(y - 1 >= 0 && grid[x][y - 1] == '1'){
            traverseGrid(x, y - 1, numberOfRows, numberOfColumns, grid);
        }
        
        if(y + 1 < numberOfColumns && grid[x][y + 1] == '1'){
            traverseGrid(x, y + 1, numberOfRows, numberOfColumns, grid);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int numberOfRows = grid.size();
        int numberOfIslands = 0;
        
        for(int i = 0; i < numberOfRows; i++){
            
            int numberOfColumns = grid[i].size();
            for(int j = 0; j < numberOfColumns; j++){
                if(grid[i][j] == '1'){
                    numberOfIslands++;
                    traverseGrid(i, j, numberOfRows, numberOfColumns, grid);
                }
            }
        }
        
        return numberOfIslands;
    }
};
