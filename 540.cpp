class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1000000007LL;
        
        long long same = 6; // patterns like ABA
        long long diff = 6; // patterns like ABC
        
        for (int i = 2; i <= n; ++i) {
            long long newSame = (3 * same + 2 * diff) % MOD;
            long long newDiff = (2 * same + 2 * diff) % MOD;
            same = newSame;
            diff = newDiff;
        }
        
        return (same + diff) % MOD;
    }
};
