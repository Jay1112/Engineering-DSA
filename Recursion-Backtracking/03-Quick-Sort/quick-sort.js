/**
 * @param {number[]} nums
 * @return {number[]}
 */

function findPivotIndex(nums, low, high){
    let j = low - 1;
    let key = nums[high];
    for(let i = low; i < high; i++){
        if(nums[i] <= key){
            j++;
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    [nums[high], nums[j+1]] = [nums[j+1], nums[high]];
    return j+1;
}

function quickSort(nums, low, high){
    if(low >= high) return;
    const pivot = findPivotIndex(nums, low, high);
    quickSort(nums, low, pivot-1);
    quickSort(nums, pivot+1, high);
}

var sortArray = function(nums) {
    quickSort(nums, 0, nums.length - 1);
    return nums;
};