class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> result;
        int i = low, j = mid + 1;

        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                result.push_back(nums[i++]);
            }else{
                result.push_back(nums[j++]);
            }
        }

        while(i <= mid){
            result.push_back(nums[i++]);
        }

        while(j <= high){
            result.push_back(nums[j++]);
        }

        for(int i = 0; i < high - low + 1; i++){
            nums[low + i] = result[i];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high){
        if(low >= high){
            return;
        }
        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};