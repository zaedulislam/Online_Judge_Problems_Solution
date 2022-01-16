/**
 * @param {number} num
 * @return {boolean}
 */
 var isPerfectSquare = function(num) {
    let first = 0.0, last = num;
    for(let step = 1; step <= 64; step++){
        let mid = (first + last) / 2;
        
        let square = Math.floor(mid) * Math.floor(mid);
        
        if(square === num){
            return true;
        } else if(square > num){
            last = mid;
        } else {
            first = mid;
        }
    }
    
    return false;
};