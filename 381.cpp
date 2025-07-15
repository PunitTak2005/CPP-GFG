#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool divBy13(string &s) {
        // Convert the string to an integer
        int num = stoi(s);

        // Check if the number is divisible by 13
        return (num % 13 == 0);
    }
};

int main() {
    string s = "2911285";

    Solution sol;
    bool isDivisible = sol.divBy13(s);

    if (isDivisible) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
