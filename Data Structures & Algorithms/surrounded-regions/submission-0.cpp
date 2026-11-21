
class Solution {
public:

    int m, n;

    void dfs(int r, int c, vector<vector<char>>& board) {

        if(r < 0 || c < 0 || r >= m || c >= n ||
           board[r][c] != 'O') {
            return;
        }

        // Mark as safe
        board[r][c] = 'T';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], board);
        }
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        // Step 1: First and last columns
        for(int i = 0; i < m; i++) {

            if(board[i][0] == 'O') {
                dfs(i, 0, board);
            }

            if(board[i][n-1] == 'O') {
                dfs(i, n-1, board);
            }
        }

        // Step 2: First and last rows
        for(int j = 0; j < n; j++) {

            if(board[0][j] == 'O') {
                dfs(0, j, board);
            }

            if(board[m-1][j] == 'O') {
                dfs(m-1, j, board);
            }
        }

        // Step 3: Convert surrounded O to X
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                else if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
