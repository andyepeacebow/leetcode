class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            vector<int> vec;
            return vec;
        }
        
        vector<vector<int>> dp;
        for (int i = 0; i < 2; i ++) {
            vector<int> line(rowIndex + 1, 0);
            dp.push_back(line);
        }
        
        int pre = 0, cur = 1;
        for (int i = 1; i <= rowIndex + 1; i ++) {
            for (int j = 0; j < i; j ++) {
                if (j == 0 || j == i - 1) {
                    dp[cur][j] = 1;
                } else {
                    dp[cur][j] = dp[pre][j - 1] + dp[pre][j];
                }
            }
            swap(pre, cur);
        }
        
        return dp[pre];
    }
};