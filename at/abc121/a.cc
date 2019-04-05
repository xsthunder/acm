#include<iostream>
using namespace std;
int main(){
    int W,H,h,w;
    while(cin>>W>>H>>w>>h){
        cout<<W*H-(h*W+H*w)+w*h<<endl;
    }
    return 0;
}
