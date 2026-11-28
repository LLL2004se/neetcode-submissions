class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;

        int sum = 0, ans = 0;

        for (int num : nums) {
            sum = ((sum + num) % k + k) % k;

            ans += freq[sum];
            freq[sum]++;
        }

        return ans;
    }
};