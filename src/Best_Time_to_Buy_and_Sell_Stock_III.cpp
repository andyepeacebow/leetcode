class Solution {
public:
	vector<int> later, pre, gap_later, gap_pre;
    int maxProfit(vector<int> &prices) {
		int n = prices.size();
		if (!n) return 0;

		later.resize(n + 2);
		later[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i --) {
			later[i] = max(prices[i], later[i + 1]);
		}
		pre.resize(n + 2);
		pre[0] = prices[0];
		for (int i = 1; i < n; i ++) {
			pre[i] = min(pre[i - 1], prices[i]);
		}

		gap_later.resize(n + 2);
		gap_later[n - 1] = 0;
		for (int i = n - 1; i >= 0; i --) {
			int once = later[i] - prices[i];
			gap_later[i] = max(gap_later[i + 1], once);
		}

		gap_pre.resize(n + 2);
		gap_pre[0] = 0;
		for (int i = 1; i < n; i ++) {
			int once = prices[i] - pre[i];
			gap_pre[i] = max(gap_pre[i - 1], once);
		}

		int res = -1;
		for (int i = 0; i < n; i ++) {
			int once = gap_pre[i] + gap_later[i];
			res = max(res, once);
		}

		return res;
    }
};