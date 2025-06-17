
#include <iostream>
using namespace std;

int digitSum(int n);



int main() {
    cout<<"result: "<<digitSum(1729);
    
    return 0;
}
int digitSum(int n){
    if(n/10==0) return n;
    return n%10+digitSum(n/10);
    
}
