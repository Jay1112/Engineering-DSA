function valid(board, row, col, ch){
    for(let i = 0; i < 9; i++){
        if(board[row][i] === ch){
            return false;
        }

        if(board[i][col] === ch){
            return false;
        }

        let rowIndex = 3 * Math.floor(row / 3) + Math.floor(i / 3);
        let colIndex = 3 * Math.floor(col / 3) + Math.floor(i % 3);

        if(board[rowIndex][colIndex] === ch){
            return false;
        }
    }
    return true;
} 

function solve(board){
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            if(board[i][j] === '.'){
                for(let k = 1; k <= 9; k++){
                    const ch = `${k}`;
                    if(valid(board, i, j, ch)){
                        board[i][j] = ch;
                        if(solve(board)){
                            return true;
                        }else{
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

var solveSudoku = function(board) {
    const ch = solve(board);
};