class Solution {
public:
    int dirx[4] = {0, 1, 0, -1}, diry[4] = {1, 0, -1, 0};
    int dir;
    

    vector<vector<int> > generateMatrix(int n) {
        vector< vector<int> > ans;
        if (n == 0) return ans;
        
        for (int i = 0; i < n; i ++) {
            vector<int> vec(n, 0);
            ans.push_back(vec);
        }
        
        dir = 0;
        int step = 0;
        int x = 0, y = 0;
        while (step < n * n) {
            ans[x][y] = step + 1, step ++;
            
    		if (step >= n * n) break;
            int xx = x + dirx[dir];
            int yy = y + diry[dir];
            // change direction
            if (xx < 0 || xx >= n || yy < 0 || yy >= n || ans[xx][yy] != 0) {
                dir = (dir + 1) % 4;
                xx = x + dirx[dir];
                yy = y + diry[dir];
            }
            x = xx, y = yy;
        }
        
        return ans;
    }
};