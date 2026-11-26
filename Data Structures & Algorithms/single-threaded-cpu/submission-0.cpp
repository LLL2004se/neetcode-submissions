
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // Store {enqueueTime, processingTime, index}
        vector<array<long long, 3>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({
                tasks[i][0],
                tasks[i][1],
                i
            });
        }

        // Sort by enqueue time
        sort(v.begin(), v.end());

        // Min heap: {processingTime, index}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            // Add all available tasks
            if (pq.empty() && i < n && time < v[i][0]) {
                time = v[i][0];
            }

            while (i < n && v[i][0] <= time) {
                pq.push({v[i][1], v[i][2]});
                i++;
            }

            // Process shortest task
            auto [processingTime, index] = pq.top();
            pq.pop();

            ans.push_back(index);
            time += processingTime;
        }

        return ans;
    }
};
