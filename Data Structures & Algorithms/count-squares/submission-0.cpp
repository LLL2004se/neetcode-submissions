
class CountSquares {
private:
    vector<vector<int>> cnt;

public:
    CountSquares() {
        cnt.resize(1001, vector<int>(1001, 0));
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        cnt[x][y]++;
    }

    int count(vector<int> point) {

        int x1 = point[0];
        int y1 = point[1];

        int ans = 0;

        // Choose another point on the same vertical line
        for (int y2 = 0; y2 <= 1000; y2++) {

            if (y2 == y1) continue;

            int side = abs(y2 - y1);

            // Check both possible horizontal directions
            for (int x2 : {x1 - side, x1 + side}) {

                if (x2 < 0 || x2 > 1000) continue;

                ans += cnt[x1][y2]
                     * cnt[x2][y1]
                     * cnt[x2][y2];
            }
        }

        return ans;
    }
};
