#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        int n = height.size();
        vector<tuple<int,int,int>> boxes; // (h, b1, b2) with b1 >= b2

        // Generate all 3 rotations for each box
        for (int i = 0; i < n; ++i) {
            int h = height[i], w = width[i], l = length[i];
            // h as height
            boxes.emplace_back(h, max(w,l), min(w,l));
            // w as height
            boxes.emplace_back(w, max(h,l), min(h,l));
            // l as height
            boxes.emplace_back(l, max(h,w), min(h,w));
        }

        // Sort by base area descending (b1 * b2), or lexicographically by (b1, b2)
        sort(boxes.begin(), boxes.end(), [](const auto& a, const auto& b){
            int b1a = get<1>(a), b2a = get<2>(a);
            int b1b = get<1>(b), b2b = get<2>(b);
            if (b1a != b1b) return b1a > b1b;
            return b2a > b2b;
        });

        int m = boxes.size();
        vector<long long> dp(m);
        long long ans = 0;

        for (int i = 0; i < m; ++i) {
            int h = get<0>(boxes[i]);
            int b1 = get<1>(boxes[i]);
            int b2 = get<2>(boxes[i]);
            dp[i] = h;

            for (int j = 0; j < i; ++j) {
                int b1j = get<1>(boxes[j]);
                int b2j = get<2>(boxes[j]);
                // Strictly smaller base
                if (b1 < b1j && b2 < b2j) {
                    dp[i] = max(dp[i], dp[j] + h);
                }
            }
            ans = max(ans, dp[i]);
        }

        return (int)ans;
    }
};
