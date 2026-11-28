class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        long long ans = -1;

        for (int num : nums) {
            if (sum > num) {
                ans = sum + num;
            }
            sum += num;
        }

        return ans;
    }
};