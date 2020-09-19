/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let lastBestPosition = nums.length - 1;
    
    for(let pos = nums.length - 1; pos >= 0; pos--){
        if(pos + nums[pos] >= lastBestPosition){
            lastBestPosition = pos; 
        }
    }
    
    return lastBestPosition === 0;
};