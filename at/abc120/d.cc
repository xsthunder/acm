#include<iostream>
#include<cstring>
using namespace std;
const int N = 2e5 + 1000;
typedef long long ll;
ll f[N];
ll A[N], B[N];
ll ans[N];
ll find_f(ll x){
    return f[x]<0?x:f[x] = find_f(f[x]);
}
void merge_f(ll a, ll b){
    ll na = -f[a];
    ll nb = -f[b];
    if( na > nb ){
        swap(a,b);
        swap(na,nb);
    }
    f[a] = b;
    f[b] = -(na+nb);
}
ll cal_set(ll x){
    return x*(x-1)/2;
}
int main(){
    ll n,m;
    while(cin>>n>>m){
        ll connected = 0;
        ans[m+1] = 0;
        for(int i = 1 ;i<=n;i++){ f[i] = -1; }
        for(int i = 1;i<=m;i++){ cin>>A[i]>>B[i]; }
        for(int i = m;i>=1;i--){
            ll fa = find_f(A[i]);
            ll fb = find_f(B[i]);
            if( fa == fb ){ 
                ans[i] = connected;
                continue;
            }
            ll tmp1 = cal_set( - f[fa]) + cal_set( - f[fb]);
            ll tmp2 = cal_set( - (f[fa] + f[fb] ));
            connected = connected - tmp1 + tmp2;
            merge_f(fa, fb);
            ans[i] = connected;
        }
        ll tmp = cal_set(n);
        for(int i = 2;i<=m+1;i++){
            cout<<tmp - ans[i]<<endl;
            //cout<<ans[i]<<endl;
        }
    }
    return 0;
}
