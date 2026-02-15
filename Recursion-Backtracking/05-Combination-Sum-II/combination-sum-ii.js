/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */

function findPermutations(index, n, curr_sum, target, curr, result, m, candidates){
    if(curr_sum === target){
        const resultArr = [...curr];
        const sortedArr = resultArr.sort((a,b) => a - b);
        const key = JSON.stringify(sortedArr);
        if(!m.hasOwnProperty(key)){
            m[key] = true;
            result.push(sortedArr);
        }
        return;
    }

    if(index === n || curr_sum > target) return;

    curr.push(candidates[index]);
    findPermutations(index + 1, n, curr_sum + candidates[index], target, curr, result, m, candidates);
    curr.pop();
    let element = candidates[index];
    while(index < n && element === candidates[index]){
        index++;
    }
    findPermutations(index, n, curr_sum, target, curr, result, m, candidates);
}

var combinationSum2 = function(candidates, target) {
    const result = [];
    const curr = [];
    const m = {};

    findPermutations(0, candidates.length, 0, target, curr, result, m, candidates);

    return result;
};