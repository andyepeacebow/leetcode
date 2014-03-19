class Solution {
public:

    int bs (int A[], int n, int target) {
        int lb = 0, ub = n;
        while (lb + 1 < ub) {
            int md = (lb + ub) >> 1;
            if (A[md] >= target) {
                ub = md;
            } else {
                lb = md;
            }
        }
        
        if (A[lb] >= target) {
            lb --;
        }
        
        return lb + 1;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        ans.resize(2);
        
        int lb = bs(A, n, target);
        if (lb >= n || A[lb] != target) {
            ans[0] = ans[1] = -1;
            return ans;
        }
        
        int ub = bs(A, n, target + 1);
		if (ub >= n || A[ub] > target) {
			ub --;
		}

        ans[0] = lb;
        ans[1] = ub;
        return ans;
    }
};