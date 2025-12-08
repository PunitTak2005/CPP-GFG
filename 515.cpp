class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        
        // Iterate through all possible values for 'c' from 1 to n
        for (int c = 1; c <= n; ++c) {
            int c_squared = c * c;
            
            // Iterate through all possible values for 'a' from 1 up to c-1
            for (int a = 1; a < c; ++a) {
                int a_squared = a * a;
                
                // Calculate b_squared = c^2 - a^2
                int b_squared = c_squared - a_squared;
                
                // Calculate b = sqrt(b_squared)
                int b = std::sqrt(b_squared);
                
                // 1. Check if 'b' is an integer (i.e., if b_squared is a perfect square)
                if (b * b == b_squared) {
                    
                    // 2. Check if 'b' is within the constraint 1 <= b <= n
                    // We already know b >= 1 and b <= c. 
                    // So we only need to check if b is not greater than n. 
                    // Since we iterate c up to n, this check is implicitly handled if b <= c,
                    // but for completeness and adherence to the constraints (in case the loops change), 
                    // we explicitly check b <= n. 
                    // For this specific loop structure, we only need to check b <= n.
                    if (b <= n) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
