#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    for (int i = 1; i <= 10; i++) {
        if (i == 6) //If i equals 6, continue to next 
                    //iteration without printing
            continue;
        cout << i << " "; 
    }  
    return 0; 
}
