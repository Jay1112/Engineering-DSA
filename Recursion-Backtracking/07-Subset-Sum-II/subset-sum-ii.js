/**
 * @param {number[]} nums
 * @return {number[][]}
 */

function findSubsets(index, n, curr, result, m, nums){
    if(index === n){
        const temp = [...curr].sort((a,b) => a - b);
        const sortkey = JSON.stringify(temp);
        if(!m.hasOwnProperty(sortkey)){
            result.push(temp);
            m[sortkey] = true;
        }
        return;
    }
    findSubsets(index + 1, n, curr, result, m, nums);
    curr.push(nums[index]);
    findSubsets(index + 1, n, curr, result, m, nums);
    curr.pop();
}

var subsetsWithDup = function(nums) {
    let result = [];
    let curr = [];
    let m = {};

    findSubsets(0, nums.length, curr, result, m, nums);

    return result;
};