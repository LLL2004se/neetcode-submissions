
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Boundary and water check
        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            grid[r][c] == '0') {
            return;
        }

        // Mark visited
        grid[r][c] = '0';

        // Explore all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1') {
                    islands++;

                    // Explore the entire island
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
