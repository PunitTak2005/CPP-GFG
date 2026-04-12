//switch statement to demonstrate multiple cases with unique labels
#include <stdio.h>

int main() {

   char n='C';
  switch(n)
  {
    case 'A': 
    case 'B': 
       printf("A and B\n");
      break;
      
    case 'C':
    case 'D':
      printf("C and D\n");
      break;
      
    default:printf("Alphabet is greater than D\n");
      break;
  }
  return 0;
        
}
