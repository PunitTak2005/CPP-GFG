#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    int n = 1;
label:
    cout << n << " ";
    n++;
    if (n <= 5)
        goto label;
    return 0;
}
