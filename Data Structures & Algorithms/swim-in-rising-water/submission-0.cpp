
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if (x == n - 1 && y == n - 1) {
                return time;
            }

            if (time > dist[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 &&
                    nx < n && ny < n) {

                    int newTime = max(time, grid[nx][ny]);

                    if (newTime < dist[nx][ny]) {
                        dist[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};
