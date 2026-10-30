class Solution {
private:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int columnSize;
    int rowSize;

    bool isOutOfBounds(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'T';

        int x, y;
        for(int k = 0; k < 4; k++){
            x = dir[k][0] + i;
            y = dir[k][1] + j;

            if(!isOutOfBounds(x, y) && board[x][y] == 'O') {
                dfs(board, x, y);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        columnSize = board.size();
        rowSize = board[0].size();

        for(int i = 0; i < rowSize; i++) {
            if(board[0][i] == 'O') {
                dfs(board, 0, i);
            }

            if(board[columnSize-1][i] == 'O') {
                dfs(board, columnSize-1, i);
            }
        }

        for(int i = 0; i < columnSize; i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            if(board[i][rowSize-1] == 'O') {
                dfs(board, i, rowSize-1);
            }
        }

        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }

    }
};
