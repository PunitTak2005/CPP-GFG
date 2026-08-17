class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;
        vector<int> jump(N + 1, -1);

        // Store ladders
        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        // Store snakes
        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        vector<int> dist(N + 1, -1);
        queue<int> q;

        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int cell = q.front();
            q.pop();

            if (cell == N) return dist[cell];

            for (int dice = 1; dice <= 6; dice++) {
                int next = cell + dice;

                if (next > N) continue;

                // Apply snake or ladder immediately
                if (jump[next] != -1) {
                    next = jump[next];
                }

                if (dist[next] == -1) {
                    dist[next] = dist[cell] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};
