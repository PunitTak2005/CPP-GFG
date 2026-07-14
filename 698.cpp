class Solution {

  public:
    // Function to calculate the result based on the given array
    int find(vector<int>& arr) {
        // Initialize num to 0
        int num = 0;

        // Get the size of the array
        int n = arr.size();

        // Loop through the array from end to start
        for (int i = n - 1; i >= 0; i--) {

            // Update num by rounding the average of the current element and the
            // previous value of num
            num = round((double)(arr[i] + num) / 2.0);
        }

        // Return the final value of num
        return num;
    }
};
