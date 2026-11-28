class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long repaired = 0;

            for (int rank : ranks) {
                repaired += sqrt(mid / rank);

                if (repaired >= cars) break;
            }

            if (repaired >= cars) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};