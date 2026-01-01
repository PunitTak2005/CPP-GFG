class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;                 // we need to add 1

        for (int i = n - 1; i >= 0 && carry; --i) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry) {                   // e.g. 9 -> 10, 999 -> 1000
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
