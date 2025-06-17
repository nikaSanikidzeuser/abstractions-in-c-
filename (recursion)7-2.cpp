
#include <iostream>
using namespace std;

int raiseToPower(int n, int k);



int main() {
    cout<<"result: "<<raiseToPower(3,4);
    
    return 0;
}
int raiseToPower(int n, int k){
    if(k==0) return 1;
    return  n*raiseToPower(n,k-1);
    
}
