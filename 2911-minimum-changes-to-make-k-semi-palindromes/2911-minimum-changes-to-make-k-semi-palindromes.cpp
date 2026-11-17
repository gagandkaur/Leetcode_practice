class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Step 1: Precompute semi-palindrome conversion costs
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                cost[i][j] = INT_MAX;

                // Try all proper divisors of len
                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Compare characters in each group
                    for (int r = 0; r < d; r++) {
                        int left = i + r;
                        int right = i + len - d + r;

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Step 2: DP to partition into exactly k substrings
        const int INF = 1e9;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = 2 * parts; i <= n; i++) {
                for (int j = 2 * (parts - 1); j <= i - 2; j++) {
                    if (dp[parts - 1][j] == INF)
                        continue;

                    dp[parts][i] = min(
                        dp[parts][i],
                        dp[parts - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};