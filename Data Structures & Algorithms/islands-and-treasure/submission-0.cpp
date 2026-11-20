
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;

        // Add all gates to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int directions[5] = {0, 1, 0, -1, 0};

        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + directions[d];
                int nc = c + directions[d + 1];

                // Check boundaries and empty room
                if (nr < 0 || nc < 0 ||
                    nr >= m || nc >= n ||
                    rooms[nr][nc] != INT_MAX) {
                    continue;
                }

                rooms[nr][nc] = rooms[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};
