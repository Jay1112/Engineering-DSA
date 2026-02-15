// User function Template for javascript

/**
 * @param {number[]} arr
 * @return {number[]}
 */

class Solution {
    
    findSums(index, n, curr_sum, arr, result, curr){
        if(index === n){
            result.push(curr_sum);
            return;
        }
        
        this.findSums(index + 1, n, curr_sum, arr, result);
        curr_sum += arr[index];
        this.findSums(index + 1, n, curr_sum, arr, result);
        curr_sum -= arr[index];
    }
    
    subsetSums(arr) {
        const result = [];
        const curr = [];
        this.findSums(0, arr.length, 0, arr, result);
        return result;
    }
}
