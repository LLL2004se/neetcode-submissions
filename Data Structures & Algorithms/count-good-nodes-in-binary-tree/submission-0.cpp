
class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, int maxVal) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= maxVal) {
            count++;
            maxVal = root->val;
        }

        dfs(root->left, maxVal);
        dfs(root->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }
};
