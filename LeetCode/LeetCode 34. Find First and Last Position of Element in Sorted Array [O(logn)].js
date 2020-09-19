/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let firstPosition = getLowerOrUpperBound(nums, target, 1);
    let lastPosition = getLowerOrUpperBound(nums, target, 2);
    
    return [firstPosition, lastPosition];
};

function getLowerOrUpperBound(nums, target, indicator){
    let first = 0;
    let last = nums.length;
    let position = -1;

    while(first <= last){
        let mid = Math.floor((first + last) / 2);

        if(nums[mid] === target){
            position = mid;
            
            if(indicator === 1){
                last = mid - 1;    
            } else{
                first = mid + 1;   
            }
        } 
        else if(nums[mid] > target){
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    
    return position;
}

