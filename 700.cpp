#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxA = *max_element(nums.begin(), nums.end());
        
        vector<int> cnt(maxA + 1, 0);
        for (int x : nums) cnt[x]++;
        
        // multi[g] = number of elements in nums divisible by g
        vector<long long> multi(maxA + 1, 0);
        for (int g = 1; g <= maxA; ++g) {
            for (int k = g; k <= maxA; k += g) {
                multi[g] += cnt[k];
            }
        }
        
        // exact[g] = number of pairs with gcd exactly g
        vector<long long> exact(maxA + 1, 0);
        for (int g = maxA; g >= 1; --g) {
            long long c = multi[g];
            if (c >= 2) {
                long long totalPairs = c * (c - 1) / 2;
                long long sub = 0;
                for (int k = 2 * g; k <= maxA; k += g) {
                    sub += exact[k];
                }
                exact[g] = totalPairs - sub;
            }
        }
        
        // prefix over counts to map index -> gcd value
        vector<long long> pref(maxA + 1, 0);
        for (int g = 1; g <= maxA; ++g) {
            pref[g] = pref[g - 1] + exact[g];
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (long long q : queries) {
            // find smallest g with pref[g] > q
            int lo = 1, hi = maxA, res = maxA;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (pref[mid] > q) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};
