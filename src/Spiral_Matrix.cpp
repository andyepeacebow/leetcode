class Solution {
public:
	vector<vector<int>> vis;
	vector<int> ans;
	int m, n;

	bool judge(int x, int y) {
		if (x < 0 || x >= m || y < 0 || y >= n) return false;
		if (vis[x][y]) return false;
		return true;
	}

	void move(int &x, int &y, int &dir) {
		int dirx[] = {0, 1, 0, -1};
		int diry[] = {1, 0, -1, 0};
		int xx = x + dirx[dir];
		int yy = y + diry[dir];
		bool ok = judge(xx, yy);
		if (!ok) {
			dir = (dir + 1) % 4;
			xx = x + dirx[dir];
			yy = y + diry[dir];
		}
		x = xx, y = yy;
	}

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		m = matrix.size();
		if (!m) return ans;
		n = matrix[0].size();
		if (!n) return ans;

		vector<int> tmp(n + 1, 0);
		for (int i = 0; i <= m; i ++) {
			vis.push_back(tmp);
		}

		
		int x = 0, y = 0, dir = 0;
		int ix = 0, iy = 0;
		for (int i = 0; i < n * m; i ++) {
			ans.push_back(matrix[x][y]);
			vis[x][y] = 1;
			move(x, y, dir);
			

			iy ++;
			if (iy >= n) {
				ix ++;
				iy = 0;
			}
		}

		return ans;
    }
};