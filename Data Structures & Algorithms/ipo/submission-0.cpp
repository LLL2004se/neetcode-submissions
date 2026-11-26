
class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();

        // Store {required capital, profit}
        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort projects by required capital
        sort(projects.begin(), projects.end());

        // Max heap to select maximum profit
        priority_queue<int> pq;

        int i = 0;

        while (k--) {

            // Add all affordable projects
            while (i < n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }

            // No affordable project available
            if (pq.empty()) {
                break;
            }

            // Select project with maximum profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
