class Solution {
private:
    // Computes GCD for normalization
    long long compute_gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Computes combinations n choose k (nCk)
    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        if (k > n / 2) k = n - k;
        
        // Optimized for k=2 and k=4, which are the only values needed
        if (k == 2) return (long long)n * (n - 1) / 2;
        if (k == 4) return (long long)n * (n - 1) * (n - 2) * (n - 3) / 24;
        
        return 0; // Should not be reached with k=2 or k=4
    }

    // Structure for the Canonical Slope Key
    struct SlopeKey {
        long long dx, dy;
        bool operator<(const SlopeKey& other) const {
            if (dx != other.dx) return dx < other.dx;
            return dy < other.dy;
        }
    };

    // Structure for the Canonical Line Key (Slope + Intercept)
    struct LineKey {
        SlopeKey slope;
        long long intercept; // Normalized intercept key
        bool operator<(const LineKey& other) const {
            if (slope.dx != other.slope.dx) return slope.dx < other.slope.dx;
            if (slope.dy != other.slope.dy) return slope.dy < other.slope.dy;
            return intercept < other.intercept;
        }
    };

public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;
        long long total_trapezoids = 0;

        // Maps for geometric hashing
        map<SlopeKey, int> slope_counts; // Counts for C_parallel
        map<pair<long long, long long>, int> midpoint_counts; // Counts for P
        map<LineKey, set<int>> line_points; // Sets for Q_collinear

        // Iterate over all pairs of points (P_i, P_j) where i < j
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];

                // 1. Calculate and Normalize Slope
                long long dx = x2 - x1;
                long long dy = y2 - y1;
                long long g = compute_gcd(abs(dx), abs(dy));
                
                SlopeKey slope_key = {dx / g, dy / g};
                
                // Canonical Normalization (first non-zero component should be positive)
                if (slope_key.dx < 0 || (slope_key.dx == 0 && slope_key.dy < 0)) {
                    slope_key.dx = -slope_key.dx;
                    slope_key.dy = -slope_key.dy;
                }

                // A. For C_parallel: Count segments per slope
                slope_counts[slope_key]++;

                // B. For P: Count segments per midpoint (using sum of coordinates as key)
                midpoint_counts[{x1 + x2, y1 + y2}]++;

                // C. For Q_collinear: Group points by canonical line (slope + intercept)
                LineKey line_key;
                line_key.slope = slope_key;
                
                if (slope_key.dx != 0) {
                    // Non-vertical line: y = m*x + b -> b = (y*dx - x*dy) / dx. 
                    // Use the numerator of the normalized intercept as the key
                    line_key.intercept = y1 * slope_key.dx - x1 * slope_key.dy;
                } else {
                    // Vertical line: x = x1. Use x1 as the key.
                    line_key.intercept = x1;
                }
                
                line_points[line_key].insert(i);
                line_points[line_key].insert(j);
            }
        }

        // --- Calculate C_parallel (Total Parallel Segment Pairs) ---
        long long C_parallel = 0;
        for (auto const& [slope, count] : slope_counts) {
            C_parallel += nCk(count, 2);
        }

        // --- Calculate P (Parallelograms) ---
        long long P = 0;
        for (auto const& [midpoint_sum, count] : midpoint_counts) {
            P += nCk(count, 2);
        }

        // --- Calculate Q_collinear (Collinear Quadruplets) ---
        long long Q_collinear = 0;
        for (auto const& [line, indices] : line_points) {
            int k = indices.size();
            if (k >= 4) {
                Q_collinear += nCk(k, 4);
            }
        }

        // --- Final Result using Inclusion-Exclusion ---
        total_trapezoids = C_parallel - P - 3 * Q_collinear;
        
        return (int)total_trapezoids;
    }
};
