class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                // try to move j further to increase distance
                j++;
            } else {
                // nums1[i] > nums2[j], so increase i to try smaller nums1[i]
                i++;
            }
        }
        return ans;
    }
};
