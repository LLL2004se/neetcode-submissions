class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> users;

        int n = username.size();

        for (int i = 0; i < n; i++) {
            users[username[i]].push_back({timestamp[i], website[i]});
        }

        map<vector<string>, int> freq;

        for (auto& [user, visits] : users) {
            sort(visits.begin(), visits.end());

            set<vector<string>> patterns;
            int m = visits.size();

            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    for (int k = j + 1; k < m; k++) {
                        patterns.insert({
                            visits[i].second,
                            visits[j].second,
                            visits[k].second
                        });
                    }
                }
            }

            for (auto& pattern : patterns) {
                freq[pattern]++;
            }
        }

        vector<string> ans;
        int maxFreq = 0;

        for (auto& [pattern, count] : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                ans = pattern;
            }
        }

        return ans;
    }
};