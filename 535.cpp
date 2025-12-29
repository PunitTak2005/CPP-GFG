class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();
        if (n > m) return kthElement(b, a, k);  // Make a the smaller array [web:12][web:17]
        
        int low = max(0, k - m), high = min(k, n);
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;
            
            int l1 = (cut1 == 0 ? INT_MIN : a[cut1 - 1]);
            int r1 = (cut1 == n ? INT_MAX : a[cut1]);
            int l2 = (cut2 == 0 ? INT_MIN : b[cut2 - 1]);
            int r2 = (cut2 == m ? INT_MAX : b[cut2]);
            
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);  // Kth element found [web:13][page:1]
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return -1;  // Should not reach here for valid inputs [web:15]
    }
};
