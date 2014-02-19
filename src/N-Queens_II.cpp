// there is more efficient version using bit

class Solution {
public:
    int res;
    vector<int> pos;
    
    void dfs (int r, int n) { // current row
    	if (r == n) {
    		res ++;
    		return;
    	}
    
    	for (int i = 0; i < n; i ++) { // try these columns
    		bool safe = true;
    		for (int j = 0; j < r; j ++) { // look back prev rows, check confliction
    			if (pos[j] == i || i - r == pos[j] - j || r + i == pos[j] + j) {
    				safe = false;
    				break;
    			}
    		}
    		if (safe) {
    			pos[r] = i;
    			dfs(r + 1, n);
    		}
    	}
    }
    
    int totalNQueens(int n) {
        pos.resize(n);
        res = 0;
        dfs(0, n);
        return res;
    }
};