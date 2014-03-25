class Solution {
public:
	unordered_map<char, vector<pair<int, int>>> pos;
	vector<vector<int>> vis;
	int n, m, len;
	

	bool dfs(int x, int y, int idx, vector<vector<char>> &board, string &word) {
		if (idx >= len - 1) return true;

		int dirx[] = {-1, 1, 0, 0};
		int diry[] = {0, 0, -1, 1};
		int xx, yy;

		vis[x][y] = 1;
		bool res = false;
		for (int i = 0; i < 4; i ++) {
			xx = x + dirx[i];
			yy = y + diry[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue; // out of map
			if (vis[xx][yy]) continue;

			if (board[xx][yy] == word[idx + 1]) {
				bool once = dfs(xx, yy, idx + 1, board, word);
				if (once) {
					res = true;
					break;
				}
			}
		}
		vis[x][y] = 0;

		return res;
	}

    bool exist(vector<vector<char> > &board, string word) {
		len = word.length();
		if (len == 0) return true;

		n = board.size();
		m = board[0].size();
		if (!n || !m) return false;

		// init
		vector<int> tmp(m + 1, 0);
		for (int i = 0; i < n; i ++) {
			vis.push_back(tmp);
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				char ch = board[i][j];
				pos[ch].push_back(make_pair(i, j));
			}
		}

		vector<pair<int, int>> &apos = pos[word[0]];
		bool res = false;
		for (int i = 0; i < apos.size(); i ++) {
			pair<int, int> &pa = apos[i];
			bool once = dfs(pa.first, pa.second, 0, board, word);
			if (once) {
				res = true;
				break;
			}
		}

		return res;
    }
};