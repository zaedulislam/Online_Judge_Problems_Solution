/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let firstPosition = getLowerBound(nums, target);
    let lastPosition = getUpperBound(nums, target);
    
    return [firstPosition, lastPosition];
};


function getLowerBound(nums, target){
    let first = 0;
    let last = nums.length - 1;
    let firstPosition = -1;

    while(first <= last){
        let mid = Math.floor((first + last) / 2);

        if(nums[mid] === target){
            firstPosition = mid;
            last = mid - 1;
        } 
        else if(nums[mid] > target){
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    
    return firstPosition;
}


function getUpperBound(nums, target){
    let first = 0;
    let last = nums.length - 1;
    let lastPosition = -1;

    while(first <= last){
        let mid = Math.floor((first + last) / 2);

        if(nums[mid] === target){
            lastPosition = mid;
            first = mid + 1;
        } 
        else if(nums[mid] > target){
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }

    
    return lastPosition;
}