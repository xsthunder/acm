#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	freopen("B.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 1e6 + 100,D = 10;
int F[N];
int G[N];
int G2[D][N];
void init(){
	int tmp,ans,res;
	for(int i =1;i<N;i++){
		tmp = i,ans = 1;
		while(tmp>0){
			if( res = tmp % 10 )ans *= res;
			tmp/=10;
		}
		F[i] = ans;
	}
	for(int i = 1;i<N;i++){
		ans = i;
		while( ans >= 10 ){
			if( G[ans] ){
				ans = G[ans];
				break;
			}
			ans = F[ans];
		}
		G[i] = ans;
	}
	for(int i = 1;i<D;i++){
		for(int j = 1;j<N;j++){
			G2[i][j] += G2[i][j-1] + (G[j] == i); 
		}
	}
}
void inp(){
	init();
	int q,l,r,k;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n", G2[k][r] - G2[k][l-1]);
	}
}
//B.cc by xsthunder at Thu Feb 15 22:45:06 2018

