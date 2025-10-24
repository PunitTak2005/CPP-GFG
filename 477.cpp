class Solution {
  public:
    int minOperations(vector<int>& arr) {
        double totalSum = 0;
        priority_queue<double> pq;
        
        for (int num : arr) {
            totalSum += num;
            pq.push(num);
        }
        
        double target = totalSum / 2.0;
        double reduced = 0.0;
        int steps = 0;
        
        while (reduced < target) {
            double top = pq.top();
            pq.pop();
            
            double half = top / 2.0;
            reduced += half;
            pq.push(half);
            steps++;
        }
        
        return steps;
    }
};
