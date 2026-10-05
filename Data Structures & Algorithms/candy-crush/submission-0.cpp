class Solution {
private:
    int find_dup(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (board[i][j] == 0) continue;
                if(i>0 && i<m-1) {
                    if(abs(board[i][j]) == abs(board[i-1][j]) && abs(board[i][j]) == abs(board[i+1][j])) {
                        board[i-1][j] = (-1) * abs(board[i-1][j]);
                        board[i][j] = (-1) * abs(board[i][j]);
                        board[i+1][j] = (-1) * abs(board[i+1][j]);
                        count++;
                    }
                }
                if(j>0 && j<n-1) {
                    if(abs(board[i][j]) == abs(board[i][j-1]) && abs(board[i][j]) == abs(board[i][j+1])) {
                        board[i][j-1] = (-1)*abs(board[i][j-1]);
                        board[i][j] = (-1)*abs(board[i][j]);
                        board[i][j+1] = (-1)*abs(board[i][j+1]);
                        count++;
                    }
                }
            }
        }
        return count;
    }

    void replace_dup(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int j=0; j<n; j++) {
            int write = m-1;
            for(int read = m-1; read>=0; read--) {
                if(board[read][j]>0) {
                    board[write][j] = board[read][j];
                    write--;
                }
            }
            while(write >= 0) {
                board[write][j] = 0;
                write--;
            }
        }
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        while(find_dup(board) > 0) {
            replace_dup(board);
        }
        return board;
    }
};