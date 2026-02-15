/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
function findCombinations(index, n, curr_sum, target, curr, result, m, candidates){
    if(index === n) return;
    if(curr_sum > target) return;

    if(curr_sum === target){
        const sortedArr = [...curr].sort((a,b) => a - b)
        let key = JSON.stringify(sortedArr);
        if(!m.hasOwnProperty(key)){
            result.push([...curr]);
            m[key] = true;
        }
        return;
    }

    curr.push(candidates[index]);
    findCombinations(index, n, curr_sum + candidates[index], target, curr, result, m, candidates);
    curr.pop();
    findCombinations(index + 1, n, curr_sum, target, curr, result, m, candidates);
}

var combinationSum = function(candidates, target) {
    let m = {};
    let result = [];
    let curr = [];
    findCombinations(0, candidates.length, 0, target, curr, result, m, candidates);
    return result;
};