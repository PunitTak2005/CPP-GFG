#include <stdio.h>

int main() {

      int gfg=0; // local variable for main
    printf("Before if-else block %d\n",gfg);
    if(1){
        int gfg = 100; // new local variable of if block
        printf("if block %d\n",gfg);
    }
    printf("After if block %d",gfg);
  return 0;
}
