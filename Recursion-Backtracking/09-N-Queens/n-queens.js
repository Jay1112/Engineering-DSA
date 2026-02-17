/**
 * @param {number} n
 * @return {string[][]}
 */

function generateBoard(col, n, rows, upper, lower, board, result){
    if(col === n){
        const updated = board.map((item) => item.join(""));
        result.push(updated);
        return;
    }

    for(let row = 0; row < n; row++){
        if(rows[row] === 0 && lower[row + col] === 0 && upper[n - 1 + row - col] === 0){
            board[row][col] = 'Q';
            rows[row] = 1;
            lower[row + col] = 1;
            upper[n - 1 + row - col] = 1;
            generateBoard(col + 1, n, rows, upper, lower, board, result);
            board[row][col] = '.';
            rows[row] = 0;
            lower[row + col] = 0;
            upper[n - 1 + row - col] = 0;
        }
    }
}

var solveNQueens = function(n) {
    let rows = new Array(n).fill(0);
    let upper = new Array(2*n-1).fill(0);
    let lower = new Array(2*n-1).fill(0);

    let result = [];
    let board = Array.from({ length : n },() => new Array(n).fill('.'));

    generateBoard(0, n, rows, upper, lower, board, result);

    return result;
};