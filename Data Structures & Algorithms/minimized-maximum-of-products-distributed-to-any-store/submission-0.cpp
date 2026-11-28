class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            int stores = 0;

            for (int q : quantities) {
                stores += (q + mid - 1) / mid;
            }

            if (stores <= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};