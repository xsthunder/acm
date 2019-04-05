#include<iostream>
using namespace std;
const int N = 2000;
int main(){
    int n,m,c;
    int B[N];
    while(cin>>n>>m>>c){
        for(int i = 0;i<m;i++){
            cin>>B[i];
        }
        int ans = 0;
        while(n--){
            int tmp = c;
            for(int i = 0;i<m;i++){
                int a; cin>>a;
                tmp += a*B[i];
            }
            if(tmp > 0)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
