class Solution {
private:
    int dir [4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int rowSize;
    int columnSize;

    bool isOutOfBounds(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        if(idx == word.length()) return true;

        char currChar = board[i][j];
        board[i][j] = '.';
        for(int k = 0; k < 4; k++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];

            if(!isOutOfBounds(x,y) && board[x][y] == word[idx] && dfs(board, word, x, y, idx+1)) return true;
        }
        board[i][j] = currChar;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        columnSize = board.size();
        rowSize = board[0].size();

        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(board[i][j] == word[0] && dfs(board, word, i, j, 1)) return true;
            }
        }

        return false;
    }
};

