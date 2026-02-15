/**
 * @param {number[]} nums
 * @return {number[]}
 */

function merge(arr, low, mid, high){
    const result = [];

    let i = low;
    let j = mid + 1;

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            result.push(arr[i++]);
        }else{
            result.push(arr[j++]);
        }
    }

    while(i <= mid){
        result.push(arr[i++]);
    }

    while(j <= high){
        result.push(arr[j++]);
    }

    for(let i = 0; i < result.length; i++){
        arr[low + i] = result[i];
    }
}

function mergeSort(arr, low, high){
    if(low >= high) return;
    const mid = low + Math.floor((high - low)/2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

var sortArray = function(nums) {
    mergeSort(nums, 0, nums.length - 1);
    return nums;
};