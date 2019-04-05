#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
int main(){
    ll a,b;
    while(cin>>a>>b){
        ll ans = 0;
        while(a<=b){
            ans ^= a;
            a++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
