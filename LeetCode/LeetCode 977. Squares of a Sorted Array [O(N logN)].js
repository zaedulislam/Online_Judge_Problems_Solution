/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortedSquares = function(A) {
    for(let index = 0; index < A.length; index++){
        A[index] = A[index] * A[index];
    }
    
    A.sort(function(a, b){
        if(a < b){
            return -1;
        } 
        if(a > b){
            return 1;
        }
        
        return 0;
    });

    return A
};