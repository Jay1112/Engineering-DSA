class Solution {
public:

    bool valid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0 ; i < 9; i++){
            if(board[row][i] == ch){
                return false;
            }

            if(board[i][col] == ch){
                return false;
            }

            int rowIndex = 3 * (row / 3) + i / 3;
            int colIndex = 3 * (col / 3) + i % 3;

            if(board[rowIndex][colIndex] == ch){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9; i++){
            for(int j = 0 ; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k <= 9; k++){
                        char ch = (char)(48 + k);
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

    void solveSudoku(vector<vector<char>>& board) {
        bool ch = solve(board);
    }
};