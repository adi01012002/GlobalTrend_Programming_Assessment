#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(a==0) return b;
    else return gcd(b%a,a);
}
int main(){
    int a;
    cout<<"Enter a :";
    cin>>a;
    int b;
        cout<<"Enter b :";
    cin>>b;
    cout<<"GCD OF "<<a<<" and "<<b<<" is :"<<gcd(a,b);
    cout<<endl;
}