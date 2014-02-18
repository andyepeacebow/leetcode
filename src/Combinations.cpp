class Solution {
public:

    void dfs(int idx, int cnt, int n, int k, vector< vector<int> > &ans, vector<int> vec) {
        if (cnt >= k) {
            ans.push_back(vec);
            return;
        }
        
        for (int i = idx; i <= n; i ++) {
            vector<int> tmp = vec;
            tmp.push_back(i);
            dfs(i + 1, cnt + 1, n, k, ans, tmp);
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector< vector<int> > ans;
        vector<int> vec;
        
        if (n == 0 || k == 0) return ans;
        
        if (k >= n) {
            vector<int> vec;
            for (int i = 1; i <= n; i ++) vec.push_back(i);
            ans.push_back(vec);
            return ans;
        }
        
        dfs(1, 0, n, k, ans, vec);
        
        return ans;
    }
};