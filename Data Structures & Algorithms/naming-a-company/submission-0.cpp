class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> groups[26];

        for (string& idea : ideas) {
            groups[idea[0] - 'a'].insert(idea.substr(1));
        }

        long long ans = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                long long common = 0;

                for (const string& s : groups[i]) {
                    if (groups[j].count(s)) {
                        common++;
                    }
                }

                long long count1 = groups[i].size() - common;
                long long count2 = groups[j].size() - common;

                ans += 2 * count1 * count2;
            }
        }

        return ans;
    }
};