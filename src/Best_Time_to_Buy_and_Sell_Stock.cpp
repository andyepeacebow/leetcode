class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int big = prices[n - 1];
        int res = 0;
        for (int i = n - 2; i >= 0; i --) {
            int once = big - prices[i];
            res = max(res, once);
            big = max(big, prices[i]);
        }
        
        return res;
    }
};