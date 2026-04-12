//switch statement to demonstrate multiple cases with unique labels
#include <iostream>
using namespace std;

int main() 
{
  char n='C';
  switch(n)
  {
    case 'A': 
    case 'B': 
       cout<<"A and B"<<endl;
      break;
      
    case 'C':
    case 'D':
      cout<<"C and D"<<endl;
      break;
      
    default:cout<<"Alphabet is greater than D"<<endl;
      break;
  }
  return 0;
}
