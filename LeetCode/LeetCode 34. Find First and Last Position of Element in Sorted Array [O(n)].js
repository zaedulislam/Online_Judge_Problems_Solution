/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let firstPosition = -1;
    let lastPosition = -1;
    
    for(let index = 0; index < nums.length; index++){
        if(nums[index] === target && firstPosition === -1){
            firstPosition = index;
        }
        
        if(nums[index] === target){
            lastPosition = index;
        }
    }
    
    return [firstPosition, lastPosition];
};