class Solution {
public:
	vector<vector<char>> gra;
	vector<vector<int>> vis;
	int m, n;

	bool in_range(int x, int y) {
		if (x < 0 || x >= m || y < 0 || y >= n) return false;
		return true;
	}

	void bfs(int x, int y) {
		queue<pair<int, int>> que;
		que.push(make_pair(x, y));
		int dirx[] = {-1, 1, 0, 0};
		int diry[] = {0, 0, -1, 1};
		while (que.empty() == false) {
			pair<int, int> pa = que.front();
			que.pop();
			if (vis[pa.first][pa.second]) continue;
			vis[pa.first][pa.second] = 1;
			for (int i = 0; i < 4; i ++) {
				int xx = pa.first + dirx[i];
				int yy = pa.second + diry[i];
				if (in_range(xx, yy) == false) continue;
				if (gra[xx][yy] == 'X' || vis[xx][yy]) continue;
				que.push(make_pair(xx, yy));
			}
		}
	}
	
    void solve(vector<vector<char>> &board) {
		if (board.size() == 0 || board[0].size() == 0) return;
		m = board.size();
		n = board[0].size();
        gra = board;
		vector<int> tmp(n, 0);
		for (int i = 0; i < m; i ++) {
			vis.push_back(tmp);
		}
		for (int i = 0; i < n; i ++) {
			if (board[0][i] == 'O' && !vis[0][i]) {
				bfs(0, i);
			}
			if (board[m - 1][i] == 'O' && !vis[m - 1][i]) {
				bfs(m - 1, i);
			}
		}
		for (int i = 0; i < m; i ++) {
			if (board[i][0] == 'O' && !vis[i][0]) {
				bfs(i, 0);
			}
			if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
				bfs(i, n - 1);
			}
		}

		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < n; j ++) {
				if (board[i][j] == 'O' && !vis[i][j]) {
					board[i][j] = 'X';
				}
			}
		}
    }
};