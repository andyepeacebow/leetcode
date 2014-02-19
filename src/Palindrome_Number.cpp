class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
         
        int len = 0;  
        int tmp = x;
        while (tmp) {
            len ++;
            tmp /= 10;
        }
    	
        int mod1 = pow(10.0, len - 1);    
        int mod2 = 10;
        bool ok = true;
        for (int i = 0; i < len / 2; i ++) {
            int v1 = (x / mod1) % 10;
            int v2 = (x % mod2) / (mod2 / 10);
            if (v1 != v2) {
                ok = false;
                break;
            }
    		mod1 /= 10;
    		mod2 *= 10;
        }
        
        return ok;
    }
};