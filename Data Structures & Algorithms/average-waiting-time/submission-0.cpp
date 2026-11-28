class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long time = 0, total = 0;

        for (auto& c : customers) {
            time = max(time, (long long)c[0]);
            time += c[1];
            total += time - c[0];
        }

        return (double)total / customers.size();
    }
};