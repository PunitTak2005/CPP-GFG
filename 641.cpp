class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks by (minimum - actual) in descending order.
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        long long energy = 0;  // minimal initial energy we need
        long long cur = 0;     // current energy if we start with "energy"

        for (auto &t : tasks) {
            int actual = t[0];
            int minimum = t[1];

            // If current energy is less than required minimum, increase energy.
            if (cur < minimum) {
                long long diff = minimum - cur;
                energy += diff;
                cur += diff;
            }
            // Do the task.
            cur -= actual;
        }

        return (int)energy;
    }
};
