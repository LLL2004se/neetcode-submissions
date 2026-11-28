class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0, count = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            if (nums[right] == mx) {
                count++;
            }

            while (count >= k) {
                ans += n - right;

                if (nums[left] == mx) {
                    count--;
                }

                left++;
            }
        }

        return ans;
    }
};