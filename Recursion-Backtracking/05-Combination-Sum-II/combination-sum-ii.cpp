class Solution {
public:

    void findCombinations(int index, int n, int curr_sum, int target, vector<int>& candidates, set<vector<int>>& s, vector<int>& curr){
        if(curr_sum == target){
            vector<int> temp(curr.begin(), curr.end());
            sort(temp.begin(), temp.end());
            s.insert(temp);
            return;
        }

        if(index == n) return;
        if(curr_sum > target) return;

        curr.push_back(candidates[index]);
        findCombinations(index + 1, n, curr_sum + candidates[index], target, candidates, s, curr);
        curr.pop_back();
        int element = candidates[index];
        while(index < n && candidates[index] == element){
            index++;
        }
        findCombinations(index, n, curr_sum, target, candidates, s, curr);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> s;
        vector<int> curr;

        findCombinations(0, candidates.size(), 0, target, candidates, s, curr);

        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};