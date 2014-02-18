class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector< vector<int> > dp;
        for (int i = 0; i <= m; i ++) {
            vector<int> line(n + 1, 0);
            dp.push_back(line);
        }
        
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                int cost = grid[i - 1][j - 1];
                if (i == 1) {
                    dp[i][j] = dp[i][j - 1] + cost;
                } else if (j == 1) {
                    dp[i][j] = dp[i - 1][j] + cost;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost;
                }
            }
        }
        
        int res = dp[m][n];
        return res;
    }
};