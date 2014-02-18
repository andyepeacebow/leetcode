class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = false;
        int n = digits.size();
        if (n == 0) return digits;
        
        digits[n - 1] += 1;
        for (int i = n - 1; i >= 0; i --) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                carry = true;
                digits[i] -= 10;
            } else {
                carry = false;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};