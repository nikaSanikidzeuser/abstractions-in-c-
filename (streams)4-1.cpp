#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double j;



int main() {
    cout<<" theta "<<"| "<<"sin(theta) | cos(theta) |"<<endl;
    cout<<"-------+------------+------------+"<<endl;
    for(int i = -90; i<=90;i+=15){
        j = (i*M_PI)/180;
        cout<<right<<setw(6)<<i<<" | "<<fixed<<setprecision(7)<<setw(10)<<sin(j)<<" | "<<cos(j)<<" | "<<endl;
        
    }
}


