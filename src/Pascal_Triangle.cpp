class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector< vector<int> > vec;
        if (numRows == 0) return vec;
        
        for (int lev = 1; lev <= numRows; lev ++) {
            vector<int> cur;
            for (int i = 0; i < lev; i ++) {
                if (i == 0 || i == lev - 1) {
                    cur.push_back(1);
                } else {
                    int val = vec[lev - 2][i - 1] + vec[lev - 2][i];
                    cur.push_back(val);
                }
            }
            vec.push_back(cur);
        }
        
        return vec;
    }
};