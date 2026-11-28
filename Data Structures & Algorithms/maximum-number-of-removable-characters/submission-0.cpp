class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            vector<bool> removed(s.size(), false);

            for (int i = 0; i < mid; i++) {
                removed[removable[i]] = true;
            }

            int j = 0;

            for (int i = 0; i < s.size() && j < p.size(); i++) {
                if (!removed[i] && s[i] == p[j]) {
                    j++;
                }
            }

            if (j == p.size()) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};