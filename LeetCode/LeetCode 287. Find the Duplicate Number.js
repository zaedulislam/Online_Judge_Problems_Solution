/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    const lookUpTable = {};
    
    for(const num of nums){
       if(!lookUpTable[num]){
           lookUpTable[num] = 1;
       } else {
           return num;
       } 
    }
};