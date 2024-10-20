#include<iostream>
using namespace std;

int main(){
    int gfg=0; // local variable for main
    cout<<"Before if-else block "<<gfg<<endl;
    if(1){
        int gfg = 100; // new local variable of if block
        cout<<"if block "<<gfg<<endl;
    }
    cout<<"After if block "<<gfg<<endl; 
    return 0;
}
/*
    Before if-else block 0
    if block 100
    After if block 0
*/
