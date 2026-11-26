
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

    Node* build(vector<vector<int>>& grid, int r, int c, int n) {

        // Check whether the entire region has the same value
        bool same = true;
        int val = grid[r][c];

        for (int i = r; i < r + n; i++) {
            for (int j = c; j < c + n; j++) {
                if (grid[i][j] != val) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        // If all values are same, create a leaf node
        if (same) {
            return new Node(val, true);
        }

        // Divide into four parts
        int half = n / 2;

        Node* topLeft = build(grid, r, c, half);
        Node* topRight = build(grid, r, c + half, half);
        Node* bottomLeft = build(grid, r + half, c, half);
        Node* bottomRight = build(grid, r + half, c + half, half);

        // Create internal node
        return new Node(
            true,
            false,
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }
};
