class Solution {
public:

    void playChess(int col, int n, vector<int> rows, vector<int>& upper, vector<int> lower, vector<string>& board, vector<vector<string>>& result){
        if(col == n){
            result.push_back(board);
            return;
        }

        for(int row = 0 ; row < n; row++){
            if(rows[row] == 0 && upper[n-1+row-col] == 0 && lower[row + col] == 0){
                board[row][col] = 'Q';
                rows[row] = 1;
                upper[n-1+row-col] = 1;
                lower[row + col] = 1;
                playChess(col + 1, n, rows, upper, lower, board, result);
                board[row][col] = '.';
                rows[row] = 0;
                upper[n-1+row-col] = 0;
                lower[row + col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> rows(n, 0);
        vector<int> upper(2*n-1, 0);
        vector<int> lower(2*n-1, 0);
        vector<vector<string>> result;

        vector<string> board;
        for(int i = 0; i < n; i++){
            string line = "";
            for(int j = 0 ; j < n; j++){
                line = line + '.';
            }
            board.push_back(line);
        }

        playChess(0, n, rows, upper, lower, board, result);

        return result;
    }
};