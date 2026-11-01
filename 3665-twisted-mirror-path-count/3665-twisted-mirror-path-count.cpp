class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int n = grid[0].size();
        vector<int> down(n, 0);
        down[0] = 1;

        for (auto& row : grid) {
            int right = 0;

            for (int j = 0; j < n; j++) {
                if (row[j] == 1) {
                    swap(right, down[j]);
                } else {
                    right = down[j] = (right + (long long)down[j]) % MOD;
                }
            }
        }

        return down[n - 1];
    }
};