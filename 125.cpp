#include<iostream>
using namespace std;
//finction to print numbers from 1 to 10
void printNumbers()
{int n=1;
label:
  cout<<n<<"";
n++;
if(n<=10)
  goto label;}
int main()
{printNumbers();
return 0;}
