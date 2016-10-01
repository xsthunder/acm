#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define SC(x) scanf("%d", &(x));
typedef long long ll;
const int maxm = 1e5+10;
int m, k, p[maxm];
int solve(ll P) {
  ll sum = 0;
  int ans = 1;
  rep(i,0,m-1){
    if(sum + p[i] <= P) sum += p[i];
    else { ans++; sum = p[i]; }
  }
  return ans;
}
int main() {
    SC(m);SC(k);
    ll tot = 0;
    int P = -1;
	rep(i,0,m-1){
	  SC(p[i]);
      tot += p[i];
      P = max(P, p[i]);
    }
    ll L = P, R = tot;
    while(L < R) {
      ll M = L + (R-L)/2;
      if(solve(M)<=k)R=M; else L = M+1;
    }
    
    printf("%lld\n",L);

  return 0;
}
