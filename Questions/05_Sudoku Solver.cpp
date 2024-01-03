// https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:

    bool isSafe(char value, vector<vector<char>>& board, int curr_row, int curr_col){
        // row check
        for(int col = 0; col<9; col++){
            if(board[curr_row][col] == value)
                return false;
        }
        
        // column check
        for(int row = 0; row<9; row++){
            if(board[row][curr_col] == value)
                return false;
        }
        
        
        // 3x3 box check
        for(int i = 0; i<9; i++){
            if(board[3*(curr_row/3) + (i/3)][3*(curr_col/3) + (i%3)] == value){
                return false;
            }
        }
        
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // check for empty cell
                if(board[i][j] == '.'){
                    // try to fill with values ranging form 1 to 9
                    for(char value = '1'; value <= '9'; value++){
                        // check for safety
                        if(isSafe(value, board, i, j)){
                            // insert
                            board[i][j] = value;
                            // baaki recursion smbhal lega
                            
                            bool nextSol = solve(board);
                            if(nextSol == true){
                                return true;
                            }
                            // Backtracking
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    // if 1 to 9 we dont find solution means something went wrong on previous step
                    // go back by returning false
                    return false;
                }
            } 
        }
        // All cells filled
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
