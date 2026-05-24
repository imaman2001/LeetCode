class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int idx){

        if(idx == word.size()) return true;

        if(row<0 || col<0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        bool done = dfs(board, word, row-1, col, idx+1) || dfs(board, word, row, col+1, idx+1) || dfs(board, word, row+1, col, idx+1) || dfs(board, word, row, col-1, idx+1);

        board[row][col] = temp;

        return done;
    }
    bool exist(vector<vector<char>>& board, string word) {

        vector<int>vis(word.size(), 0);

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};