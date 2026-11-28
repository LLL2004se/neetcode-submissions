class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        int n = items.size();
        vector<int> prefix(n);

        prefix[0] = items[0][1];

        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], items[i][1]);
        }

        vector<int> ans;

        for (int q : queries) {
            int idx = upper_bound(
                items.begin(), items.end(),
                vector<int>{q, INT_MAX}
            ) - items.begin();

            ans.push_back(idx == 0 ? 0 : prefix[idx - 1]);
        }

        return ans;
    }
};