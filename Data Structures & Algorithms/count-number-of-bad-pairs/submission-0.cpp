class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total = n * (n - 1) / 2;

        unordered_map<int, long long> mp;
        long long good = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;

            good += mp[diff];
            mp[diff]++;
        }

        return total - good;
    }
};