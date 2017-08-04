#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m) memset(m,0,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("hdu6058.in","r",stdin);
#endif
	int n;scanf("%d",&n);for(int i=1;i<=n;i++) inp();
	return 0;
}
const int N = 5e5 + 100;
int n,k,A[N],Pr[N],Ne[N];
void inp(){
	MS(A),MS(Pr),MS(Ne);
	scanf("%d%d",&n,&k);
	int i,x,j;
	for ( i = 1;i<=n;i++){
		scanf("%d",&x);
		A[x] = i;
		Pr[i] = i-1;
		Ne[i] = i+1;
	}
	int lc,pr,ne,rc,pos;
	ll ans = 0;
	for( i = 1;i<=n;i++){
		lc = 0, rc = 0;
		pos = A[i];
		ne = pr = pos;
		for( j = 1;j<=k-1&&Pr[pr];j++){
			lc ++,pr = Pr[pr];
		}
		for( j = 1;j<=k-lc-1&&Ne[ne];j++){
			rc ++,ne = Ne[ne];
		}
		if(lc +rc != k -1 )continue;
		while(ne&&ne != n+1){
			ans += (ll)i * (Ne[ne] - ne)*(pr - Pr[pr]  );
			pr = Ne[pr];
			ne = Ne[ne];
			if (pos <pr)break;
			if (n + 1 == ne)break;
		}
		//del A[i]
		Pr[Ne[pos]] = Pr[pos];
		Ne[Pr[pos]] = Ne[pos];
	}
	printf("%lld\n", ans);
}
//hdu6058.cc by xsthunder at Tue Aug  1 21:18:21 2017

//AC at Wed Aug  2 09:04:47 2017
 
