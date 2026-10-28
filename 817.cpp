class Solution {
public:
    char nthCharacter(int n) {
        long long digits = 1;      // current number length
        long long count = 9;       // how many numbers have this length
        long long start = 1;       // first number with this length

        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        long long num = start + (n - 1) / digits;
        int idx = (n - 1) % digits;

        return to_string(num)[idx];
    }
};
