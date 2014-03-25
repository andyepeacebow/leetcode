class Solution {
public:
	
    int sqrt(int x) {
        if (x < 0) return 0;

		long long lb = 0, ub = x;
		
		while (lb + 1 < ub) {
			long long md = (lb + ub) / 2;
			long long sqr = md * md;
			if (sqr == x) return md;
			else if (sqr < x) {
				lb = md;
			} else {
				ub = md;
			}
		}

		long long sqr = (lb + 1) * (lb + 1);
		if (sqr == x) {
			return lb + 1;
		} else {
			return lb;
		}
    }
};