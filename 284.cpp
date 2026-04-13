class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();

        // 1) Check if all digits are 9
        bool all9 = true;
        for (int d : num) {
            if (d != 9) { all9 = false; break; }
        }
        if (all9) {
            vector<int> ans(n + 1, 0);
            ans[0] = ans[n] = 1;  // 100...001
            return ans;
        }

        // 2) General case
        int i = (n - 1) / 2;   // left middle
        int j = n / 2;         // right middle

        // Move i, j while equal
        while (i >= 0 && num[i] == num[j]) {
            --i; ++j;
        }

        bool leftSmaller = false;
        if (i < 0 || num[i] < num[j]) leftSmaller = true;

        // Mirror left -> right
        i = (n - 1) / 2;
        j = n / 2;
        while (i >= 0) {
            num[j] = num[i];
            --i; ++j;
        }

        // If left side was smaller, increment middle and propagate carry
        if (leftSmaller) {
            int carry = 1;
            i = (n - 1) / 2;
            j = n / 2;
            while (i >= 0 && carry) {
                int val = num[i] + carry;
                num[i] = val % 10;
                carry = val / 10;
                num[j] = num[i];  // keep palindrome
                --i; ++j;
            }
        }

        return num;
    }
};
