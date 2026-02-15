/**
 * @param {number[]} nums
 * @return {number[][]}
 */

function findPermutations(index, nums, result){
    if(index === nums.length){
        result.push([...nums]);
        return;
    }

    for(let i = index ; i < nums.length; i++){
        [nums[i], nums[index]] = [nums[index], nums[i]];
        findPermutations(index + 1, nums, result);
        [nums[i], nums[index]] = [nums[index], nums[i]];
    }
}

var permute = function(nums) {
    let result = [];
    findPermutations(0, nums, result);
    return result;
};