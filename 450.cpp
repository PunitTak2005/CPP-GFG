class SpecialQueue {
private:
    queue<int> q;        // Main queue
    deque<int> minDeque; // Monotonic increasing deque for min
    deque<int> maxDeque; // Monotonic decreasing deque for max

public:
    void enqueue(int x) {
        q.push(x);

        // Maintain minDeque: remove all elements larger than x from the back
        while (!minDeque.empty() && minDeque.back() > x) {
            minDeque.pop_back();
        }
        minDeque.push_back(x);

        // Maintain maxDeque: remove all elements smaller than x from the back
        while (!maxDeque.empty() && maxDeque.back() < x) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;

        int frontVal = q.front();
        q.pop();

        if (!minDeque.empty() && minDeque.front() == frontVal) {
            minDeque.pop_front();
        }
        if (!maxDeque.empty() && maxDeque.front() == frontVal) {
            maxDeque.pop_front();
        }
    }

    int getFront() {
        if (!q.empty()) return q.front();
        return -1; // Should never happen as per problem constraints
    }

    int getMin() {
        if (!minDeque.empty()) return minDeque.front();
        return -1; // Should never happen as per problem constraints
    }

    int getMax() {
        if (!maxDeque.empty()) return maxDeque.front();
        return -1; // Should never happen as per problem constraints
    }
};

// Example driver to test queries
int main() {
    SpecialQueue sq;
    vector<vector<int>> queries = {{1, 4}, {1, 2}, {3}, {4}, {2}, {5}};
    vector<int> output;

    for (auto &q : queries) {
        if (q[0] == 1) sq.enqueue(q[1]);
        else if (q[0] == 2) sq.dequeue();
        else if (q[0] == 3) output.push_back(sq.getFront());
        else if (q[0] == 4) output.push_back(sq.getMin());
        else if (q[0] == 5) output.push_back(sq.getMax());
    }

    for (int val : output) cout << val << " ";
    cout << endl;

    return 0;
}
