class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>>& board, int k, string word){
        //判断越界
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
            return false;
        }
        //判断是否访问过
        if(board[i][j] == '*'){
            return false;
        }
        //判断是否匹配
        if(board[i][j] != word[k])
            return false;
        else{
            char temp = board[i][j];
            board[i][j] = '*';
            ++k;
            if(k == word.size()){
            return true;
            }

            bool rst = dfs(i-1, j, board, k, word) || dfs(i, j+1, board, k, word) || dfs(i+1, j, board, k, word) || dfs(i, j-1, board, k, word);
            board[i][j] = temp;
            return rst;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board.size() * board[0].size() < word.size()) return false;
            for(int i = 0; i < board.size(); ++i){
                for(int j = 0; j < board[0].size(); ++j){
                    bool rst = dfs(i, j, board, 0, word);
                    if(rst == true)
                        return true;
                }
            }
        return false;
    }
};
