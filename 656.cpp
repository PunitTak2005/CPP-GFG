class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());              // O(n log n)
        
        long long cur = mass;                                  // use long long to avoid overflow
        for (int x : asteroids) {
            if (cur < x) return false;                         // cannot destroy this asteroid
            cur += x;                                          // absorb it, gain mass
        }
        return true;                                           // destroyed all
    }
};
