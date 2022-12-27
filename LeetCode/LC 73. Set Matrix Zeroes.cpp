class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowLength = matrix.size();
        int columnLength = matrix[0].size();
        bool isFirstColumn = false;

        for(int i = 0; i < rowLength; i++){
            if(matrix[i][0] == 0){
                isFirstColumn = true;
            }

            for(int j = 1; j < columnLength; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; 
                    matrix[0][j] = 0;
                }
            }
        }


        for(int i = 1; i < rowLength; i++){
            for(int j = 1; j < columnLength; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }


        if(matrix[0][0] == 0){
            for(int j = 0; j < columnLength; j++){
                matrix[0][j] = 0;
            }
        }


        if(isFirstColumn){
            for(int i = 0; i < rowLength; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
