class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        
        vector< vector<int> > dp;
        for (int i = 0; i <= m; i ++) {
            vector<int> line(n + 1, 0);
            dp.push_back(line);
        }
        dp[1][0] = 1;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
               dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        
        int res = dp[m][n];
        return res;
    }
};