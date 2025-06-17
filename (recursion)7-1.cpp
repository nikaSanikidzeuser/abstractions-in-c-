
#include <iostream>
using namespace std;

int canonball(int n);



int main() {
    cout<<"count  "<<canonball(4);
    
    return 0;
}
int canonball(int n){
    if(n==1) return 1;
    return n*n+canonball(n-1);
    
}
