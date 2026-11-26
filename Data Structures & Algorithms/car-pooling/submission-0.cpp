
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> diff(1001, 0);

        // Mark pickup and drop-off
        for (auto &t : trips) {
            int passengers = t[0];
            int start = t[1];
            int end = t[2];

            diff[start] += passengers;
            diff[end] -= passengers;
        }

        int passengers = 0;

        // Calculate prefix sum
        for (int i = 0; i <= 1000; i++) {

            passengers += diff[i];

            if (passengers > capacity) {
                return false;
            }
        }

        return true;
    }
};
