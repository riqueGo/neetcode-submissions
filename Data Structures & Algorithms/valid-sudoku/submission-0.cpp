class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            bool mem [9] = {false};
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(mem[board[i][j] - '1']) return false;
                mem[board[i][j] - '1'] = true;
            }
        }

        for(int i = 0; i < 9; i++) {
            bool mem [9] = {false};
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') continue;
                if(mem[board[j][i] - '1']) return false;
                mem[board[j][i] - '1'] = true;
            }
        }

        for(int i = 0; i <= 6; i += 3) {
            for(int j = 0; j <= 6; j += 3) {
                bool mem [9] = {false};
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        if(board[i+k][j+l] == '.') continue;
                        if(mem[board[i+k][j+l] - '1']) return false;
                        mem[board[i+k][j+l] - '1'] = true;
                    }
                }
            }
        }

        return true;
    }
};
