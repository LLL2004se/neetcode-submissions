class Solution {
    vector<int> prefix;
    int total;

public:
    Solution(vector<int>& w) {
        total = 0;

        for (int x : w) {
            total += x;
            prefix.push_back(total);
        }
    }

    int pickIndex() {
        int target = rand() % total + 1;

        return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};