
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);

        // Calculate indegree and outdegree
        for (auto &t : trust) {

            int a = t[0];
            int b = t[1];

            outDegree[a]++;
            inDegree[b]++;
        }

        // Find the town judge
        for (int i = 1; i <= n; i++) {

            if (inDegree[i] == n - 1 &&
                outDegree[i] == 0) {

                return i;
            }
        }

        return -1;
    }
};
