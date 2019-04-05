#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int N = 1e6;
P ab[N];
#define A first
#define B second
int main(){
    ll n,m;
    while(cin>>n>>m){
        for(int i = 0;i<n;i++){
            cin>>ab[i].A>>ab[i].B;
        }
        sort(ab, ab+n);
        ll ans = 0;
        int i = 0;
        while(m>0){
            int mm = min(m , ab[i].B);
            ans += mm * ab[i].A;
            m -= mm;
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
