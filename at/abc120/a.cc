#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    while( cin>>a>>b>>c ){
        if( c * a <= b ){
            cout<<c<<endl;
        }
        else  {
            cout<<b/a<<endl;
        }
    }
    return 0;
}
