class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        unordered_set<int> cols;
        unordered_set<int> diagonals;
        unordered_set<int> antiDiagonals;

        backtrack(0, n, board, cols, diagonals, antiDiagonals, ans);

        return ans;
    }

    void backtrack(int row, int n, vector<string>& board,
                   unordered_set<int>& cols,
                   unordered_set<int>& diagonals,
                   unordered_set<int>& antiDiagonals,
                   vector<vector<string>>& ans) {

        // All queens successfully placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            int diagonal = row - col;
            int antiDiagonal = row + col;

            // Check whether position is safe
            if (cols.count(col) ||
                diagonals.count(diagonal) ||
                antiDiagonals.count(antiDiagonal)) {
                continue;
            }

            // Choose: Place queen
            board[row][col] = 'Q';

            cols.insert(col);
            diagonals.insert(diagonal);
            antiDiagonals.insert(antiDiagonal);

            // Explore: Move to next row
            backtrack(row + 1, n, board,
                      cols, diagonals, antiDiagonals, ans);

            // Backtrack: Remove queen
            board[row][col] = '.';

            cols.erase(col);
            diagonals.erase(diagonal);
            antiDiagonals.erase(antiDiagonal);
        }
    }
};