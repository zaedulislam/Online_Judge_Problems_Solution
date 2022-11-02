class Solution {
public:
    queue<pair<int, int>> Q;
    
    int dx[4] = {0, -1, 0, +1};
    int dy[4] = {-1, 0, +1, 0};
    
    void BFS(vector<vector<char>>& grid, int x, int y, int numberOfRows, int numberOfColumns){
        Q.push(make_pair(x, y));
        
        while(!Q.empty()){
            pair<int, int> top = Q.front();
            Q.pop();
            
            for(int i = 0; i < 4; i++){
                int ux = top.first + dx[i];
                int uy = top.second + dy[i];
                
                if(ux >= 0 && ux < numberOfRows && uy >= 0 && uy < numberOfColumns){
                    if(grid[ux][uy] == '1'){
                        Q.push(make_pair(ux, uy));
                        grid[ux][uy] = '0';
                    }
                }
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int numberOfRows = grid.size();
        int numberOfColumns = grid[0].size();
        
        int numberOfIslands = 0;
        for(int i = 0; i < numberOfRows; i++){
            for(int j = 0; j < numberOfColumns; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    numberOfIslands++;
                    BFS(grid, i, j, numberOfRows, numberOfColumns);
                }
            }
        }
        
        return numberOfIslands;
    }
};
