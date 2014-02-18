class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> col(m);
        for (int i = 0; i < m; i ++) {
            col[i] = matrix[i][0];
        }
        
        int rid = upper_bound(col.begin(), col.end(), target) - col.begin();
        if (rid == 0) return false;
        rid --;
        
        int cid = lower_bound(matrix[rid].begin(), matrix[rid].end(), target) - matrix[rid].begin();
        if (cid >= n || matrix[rid][cid] != target) return false;
        else return true;
    }
};