class Solution {
    
public:
    // bool isSafe(vector<vector<char>>& board , int row , int col , char digit){
    //     //check vertically
    //     for(int j=0; j<9; j++){
    //         if(board[row][j] == digit){
    //             return false;
    //         }
    //     }
        
    //     //check horizontally
    //     for(int i=0; i<9; i++){
    //         if(board[i][col] == digit){
    //             return false;
    //         }
    //     }
        
    //     //3X3 grid check
    //     // int startRow = (row / 3)*3;
    //     // int startCol = (col / 3)*3;
    //     // for(int i=startRow; i<startRow+2; i++){
    //     //     for(int j=startCol; j<startCol+2; j++){
    //     //         if(board[i][j] == digit){
    //     //             return false;
    //     //         }
    //     //     }
    //     // }

    //     for(int i=0; i<9; i++){
    //         if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == digit){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool isSafe(vector<vector<char>>& board , int row , int col , char digit){
        for(int i=0; i<9; i++){
            if(board[i][col] == digit) return false;
            if(board[row][i] == digit) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == digit) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){

                if(board[i][j] == '.'){
                    for(char c='1'; c<='9'; c++){
                        if(isSafe(board , i , j , c)){
                            board[i][j] = c;
                            if(solve(board) == true){
                                return true;
                            } else {
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
    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }
};