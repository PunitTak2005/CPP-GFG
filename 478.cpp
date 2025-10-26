class Solution {
  public:
    int minCost(vector<int>& arr) {
        // If there is only one rope, no cost is required
        if (arr.size() == 1)
            return 0;

        // Create a min-heap (priority queue)
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

        int totalCost = 0;

        // Keep combining the two smallest ropes until one rope remains
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            int sum = first + second;
            totalCost += sum;

            // Push the new combined rope length back into the heap
            pq.push(sum);
        }

        return totalCost;
    }
};
