#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200;
int main(){
    int a,b,k;
    while(cin>>a>>b>>k){
        int ans[N];
        int cnt = 0;
        for(int i=max(a,b);i>=1;i--){
            if(a % i ==0 && b % i == 0){
                ans[cnt++] = i;
            }
        }
        //for(int i = 0;i<cnt;i++){
        //    cout<<ans[i]<<' ';
        //}
        cout<<ans[k-1]<<endl;
    }
    return 0;
}
