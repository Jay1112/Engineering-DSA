class Solution {
  public:
    
    void findSums(int index, int n, int curr_sum, vector<int>& arr, vector<int>& result){
        if(index == n){
            result.push_back(curr_sum);
            return;
        }
        
        findSums(index + 1, n, curr_sum, arr, result);
        curr_sum += arr[index];
        findSums(index + 1, n, curr_sum, arr, result);
        curr_sum -= arr[index];
    }
  
    vector<int> subsetSums(vector<int>& arr) {
       vector<int> result;
       
       findSums(0, arr.size(), 0, arr, result);
       
       return result;
    }
};