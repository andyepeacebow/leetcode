class Solution {
public:
	unordered_map<string, int> str2id;
	unordered_map<int, string> id2str;
	unordered_map<int, vector<int> > gra;
	int ans;
	int n;
	int MAX;

	bool judge(string &x, string &y) {
		int len = x.length();
		int dif = 0;
		for (int i = 0; i < len; i ++) {
			dif += x[i] != y[i];
			if (dif > 1) return false;
		}
		return true;
	}

	int dij(int s, int t) {
		vector<int> dist(n, MAX);
		vector<int> vis(n, 0);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		dist[s] = 0;
		pq.push(make_pair(0, s));

		while (pq.empty() == false) {
			pair<int, int> pa = pq.top();
			pq.pop();
			if (vis[pa.second]) continue;
			
			int v = pa.second;

			vis[v] = 1;
			int sz = gra[v].size();
			for (int i = 0; i < sz; i ++) {
				int u = gra[v][i];
				if (vis[u]) continue;
				
				if (dist[v] + 1 < dist[u]) {
					dist[u] = dist[v] + 1;
					pq.push(make_pair(dist[u], u));
				}
			}
		}

		int res = 0;
		if (dist[t] != MAX) {
			res = dist[t];
		}
		return res;
	}

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) return 0;
		
		MAX = 0x6fffffff;
		dict.insert(start);
		dict.insert(end);
		n = dict.size();
		unordered_set<string>::iterator it;
		int id = 0;
		int s, t;
		for (it = dict.begin(); it != dict.end(); it ++) {
			str2id[*it] = id;
			id2str[id] = *it;

			if (*it == start) {
				s = id;
			}
			if (*it == end) {
				t = id;
			}
			id ++;
		}


		for (int i = 0; i < id; i ++) {
			string &word = id2str[i];
			string copy = word;
			int len = word.size();
			for (int j = 0; j < len; j ++) {
				for (int k = 0; k < 26; k ++) {
					char pre = word[j];
					copy[j] = 'a' + k;
					if (copy == word) continue;
					
					if (dict.find(copy) != dict.end()) {
						int id = str2id[copy];
						// if ( (i == s && id == t) || (i == t && id == s) ) continue;
						gra[i].push_back(id);
					}
					copy[j] = pre;
				}
			}
		}

		int res = dij(s, t);
		if (res != 0) res ++;
		return res;
    }
};