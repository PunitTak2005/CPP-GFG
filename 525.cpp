class Solution {
  public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            bool aOdd = (a % 2 != 0);
            bool bOdd = (b % 2 != 0);
            
            // Odd numbers come before even numbers
            if (aOdd && !bOdd) return true;
            if (!aOdd && bOdd) return false;
            
            // Both are odd: descending order
            if (aOdd && bOdd) return a > b;
            
            // Both are even: ascending order
            return a < b;
        });
    }
};
