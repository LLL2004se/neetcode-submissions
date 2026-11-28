class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<long long, int>> v;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            long long mapped = 0;
            long long place = 1;

            if (num == 0) {
                mapped = mapping[0];
            } else {
                while (num > 0) {
                    int digit = num % 10;
                    mapped += 1LL * mapping[digit] * place;
                    place *= 10;
                    num /= 10;
                }
            }

            v.push_back({mapped, i});
        }

        stable_sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.first < b.first;
        });

        vector<int> ans;

        for (auto& p : v) {
            ans.push_back(nums[p.second]);
        }

        return ans;
    }
};