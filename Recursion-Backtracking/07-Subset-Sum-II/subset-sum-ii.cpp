class Solution {
public:

    void findSubsets(int index, int n, vector<int>& nums, vector<int>& curr, set<vector<int>>& s){
        if(index == n){
            vector<int> temp(curr.begin(), curr.end());
            sort(temp.begin(), temp.end());
            s.insert(temp);
            return;
        }

        findSubsets(index + 1, n, nums, curr, s);
        curr.push_back(nums[index]);
        findSubsets(index + 1, n, nums, curr, s);
        curr.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> curr;

        findSubsets(0, nums.size(), nums, curr, s);

        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};