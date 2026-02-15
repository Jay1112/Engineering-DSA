class Solution {
public:

    void findPermutation(int index, vector<int>& nums, vector<vector<int>>& result){
        if(index == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = index ; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            findPermutation(index + 1, nums, result);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> result;
         findPermutation(0, nums, result);
         return result;
    }
};