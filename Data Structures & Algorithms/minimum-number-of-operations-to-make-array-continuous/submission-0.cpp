class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> arr;
        for (int x : nums) {
            if (arr.empty() || arr.back() != x) {
                arr.push_back(x);
            }
        }

        int ans = n;
        int j = 0;

        for (int i = 0; i < arr.size(); i++) {
            while (j < arr.size() && arr[j] < arr[i] + n) {
                j++;
            }

            ans = min(ans, n - (j - i));
        }

        return ans;
    }
};