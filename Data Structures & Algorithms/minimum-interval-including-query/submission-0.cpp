class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        // {interval size, right endpoint}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int j = 0;

        for (auto [query, index] : q) {

            // Add intervals whose start <= query
            while (j < intervals.size() &&
                   intervals[j][0] <= query) {

                int left = intervals[j][0];
                int right = intervals[j][1];

                int size = right - left + 1;

                pq.push({size, right});

                j++;
            }

            // Remove intervals that cannot contain query
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};