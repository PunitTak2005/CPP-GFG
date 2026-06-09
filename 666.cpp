class Solution
{
public:
    bool canSeatAllPeople(int k, vector<int> &seats)
    {
        int n = seats.size();
        int placed = 0;

        for (int i = 0; i < n && placed < k; ++i) {
            if (seats[i] == 1) continue;

            bool leftEmpty  = (i == 0)     || (seats[i - 1] == 0);
            bool rightEmpty = (i == n - 1) || (seats[i + 1] == 0);

            if (leftEmpty && rightEmpty) {
                seats[i] = 1;
                ++placed;
            }
        }

        return placed >= k;
    }
};
