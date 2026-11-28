class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto& [c, count] : freq) {
            pq.push({count, c});
        }

        string ans = "";

        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();

            ans += string(count, c);
        }

        return ans;
    }
};