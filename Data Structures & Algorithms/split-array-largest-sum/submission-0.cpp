
class Solution {
public:

    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int parts = 1;
        int currentSum = 0;

        for (int num : nums) {

            if (currentSum + num > maxSum) {
                parts++;
                currentSum = num;
            }
            else {
                currentSum += num;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());

        int right = accumulate(nums.begin(), nums.end(), 0);

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
