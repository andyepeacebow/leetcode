class Solution {
public:
	vector<int> acc;

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
		if (n == 0) return -1;

		for (int i = 0; i < n; i ++) {
			acc.push_back(gas[i] - cost[i]);
		}

		int res = -1;
		int cur = 0, nxt = 0;
		int sum = 0;
		while (cur < n) {
			
			while (sum >= 0) {
				sum += acc[nxt];
				nxt = (nxt + 1) % n;
				if (sum < 0 || nxt == cur) {
					break;
				}
			}

			if (nxt == cur && sum >= 0) {
				res = cur;
				break;
			}

			sum -= acc[cur];
			cur = (cur + 1) % n;
			if (cur == 0) break;
		}
		

		return res;
    }
};