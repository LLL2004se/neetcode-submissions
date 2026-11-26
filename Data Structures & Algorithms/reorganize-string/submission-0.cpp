
class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : s) {
            freq[ch]++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while (pq.size() >= 2) {

            auto first = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            // Use two different characters
            ans += first.second;
            ans += second.second;

            first.first--;
            second.first--;

            // Push back if frequency remains
            if (first.first > 0) {
                pq.push(first);
            }

            if (second.first > 0) {
                pq.push(second);
            }
        }

        // Handle remaining character
        if (!pq.empty()) {
            auto last = pq.top();
            pq.pop();

            if (last.first > 1) {
                return "";
            }

            ans += last.second;
        }

        return ans;
    }
};
