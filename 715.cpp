class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {

        // Sorting the vector in place.
        sort(arr.begin(), arr.end());

        // Initializing s as 0 and total as 0.
        int s = 0;
        int total = 0;

        // Traversing through the sorted vector.
        for (int i = 1; i < arr.size(); i++) {

            // Finding the number of elements between i and s
            // with a difference greater than or equal to k.
            while (s < i && arr[i] - arr[s] >= k) {
                s++;
            }

            // Adding the count of such pairs to the total.
            total += i - s;
        }

        // Returning the total count of pairs.
        return total;
    }
};
