#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
const ll one = 1ULL;
const ll zero = 0Ull;
int main(){
    ll a,b;
    while(cin>>a>>b){
        ll n = b - a + 1;
        ll ans = 0;
        for(int i = 0;i<62;i++){
            const ll base = one<<(i+1);
            if( (one<<i)> b )break;
            const ll r = n % base;
            const ll d = n / base;
            const ll ra = a % base;

            if(i == 0){
                ans ^= d%2;// 区分odd and even T
            }
            const ll zero2ra = max(zero, ra - base/2);
            ll zero2raPr;
            if(ra+r > base){
                zero2raPr = base/2 + max(zero, (ra+r-base) - base/2);
            }
            else {
                zero2raPr = max(zero, ra + r - base/2);
            }
            ll ones =zero2raPr - zero2ra;
            if(ones&1){
                ans ^= one<<(i);
            }
            //cout<<"r"<<" "<<r<<endl;
            //cout<<"d"<<" "<<d<<endl;
            //cout<<"ra"<<" "<<ra<<endl;
            //cout<<"zero2ra"<<" "<<zero2ra<<endl;
            //cout<<"zero2raPr"<<" "<<zero2raPr<<endl;
            //cout<<'i'<<':'<<i<<" ones:"<<ones<<" ans:"<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
