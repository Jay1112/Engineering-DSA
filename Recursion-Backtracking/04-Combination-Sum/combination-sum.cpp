class Solution {
public:

    void findCombinations(int index, int n, int curr_sum, vector<int>& candidates, int target, vector<int>& curr, set<vector<int>>& s){
        if(index == n) return;
        if(curr_sum > target) return;

        if(curr_sum == target){
            s.insert(curr);
            return;
        }

        curr.push_back(candidates[index]);
        findCombinations(index, candidates.size(), curr_sum + candidates[index], candidates, target, curr, s);
        curr.pop_back();
        findCombinations(index + 1, candidates.size(), curr_sum, candidates, target, curr, s);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> s;
        vector<int> curr;
        findCombinations(0, candidates.size(), 0, candidates, target, curr, s);
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};