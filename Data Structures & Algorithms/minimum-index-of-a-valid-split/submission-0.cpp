class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums) {
            freq[num]++;
        }

        int dominant = 0, maxFreq = 0;

        for (auto& [num, count] : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                dominant = num;
            }
        }

        int leftCount = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) {
                leftCount++;
            }

            int leftSize = i + 1;
            int rightSize = n - leftSize;
            int rightCount = maxFreq - leftCount;

            if (leftCount * 2 > leftSize &&
                rightCount * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
};