
class Solution {
public:
    int m, n;

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               !visited[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(
            m, vector<bool>(n, false));

        vector<vector<bool>> atlantic(
            m, vector<bool>(n, false));

        // Pacific: Top and Left boundaries
        for(int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
        }

        for(int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
        }

        // Atlantic: Bottom and Right boundaries
        for(int i = 0; i < m; i++) {
            dfs(i, n-1, heights, atlantic);
        }

        for(int j = 0; j < n; j++) {
            dfs(m-1, j, heights, atlantic);
        }

        // Find cells reachable by both oceans
        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
