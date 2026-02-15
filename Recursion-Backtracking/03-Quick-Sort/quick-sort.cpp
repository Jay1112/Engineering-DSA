class Solution {
public:

    int findPivotIndex(vector<int>& nums, int low, int high){
        int j = low - 1;
        int key = nums[high];

        for(int i = low ; i < high; i++){
            if(nums[i] <= key){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[j+1], nums[high]);
        return j+1;
    }

    void quickSort(vector<int>& nums, int low, int high){
        if(low >= high) return;
        
        int pivot = findPivotIndex(nums, low, high);
        quickSort(nums, low, pivot-1);
        quickSort(nums, pivot+1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};