class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0; // Initially X = 0
        
        for (string op : operations) {
            if (op[1] == '+')  // Either "++X" or "X++"
                X++;
            else                // Either "--X" or "X--"
                X--;
        }
        
        return X;
    }
};
