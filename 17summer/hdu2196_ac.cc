#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
typedef vector<P > VI;
typedef vector<VI> VII;
const int N = 1e4 + 100;

void inp();
int main(){
#ifdef XS
	freopen("hdu2196.in","r",stdin);
#endif
	try{
		while(1)inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
VII vii(N);
int Mf[N];
int Ms[N];
int vf[N];
int vs[N];
void dfs1(int v,int fa){
	Mf[v] = Ms[v] =vs[v] = vf[v]=0;
	for(P p :vii[v]){
		int a = p.first ,c = p.second;
		if(a == fa)continue;
		dfs1(a, v);
		if(Mf[a] +c> Mf[v]){
			Ms[v] = Mf[v];
			vs[v] = vf[v];
			Mf[v] = Mf[a] +c;
			vf[v] = a;
		}
		else if(Mf[a] +c >Ms[v]){
			Ms[v] = Mf[a] +c;
			vs[v] = a;
		}
	}
}
void dfs2(int v,int fa ,int c){
	if(fa != -1 ){
		if(vf[fa] == v){//fa's max path go throught v
			if(Ms[fa] +c > Mf[v]){
				Ms[v] = Mf[v];
				vs[v] = vf[v];
				Mf[v] = Ms[fa] +c;
				vf[v] = fa;
			}
			else if(Ms[fa] +c >Ms[v]){
				Ms[v] = Ms[fa] +c;
				vs[v] = fa;
			}
		}
		else {
			if(Mf[fa] +c> Mf[v]){
				Ms[v] = Mf[v];
				vs[v] = vf[v];
				Mf[v] = Mf[fa] +c;
				vf[v] = fa;
			}
			else if(Mf[fa] +c >Ms[v]){
				Ms[v] = Mf[fa] +c;
				vs[v] = fa;
			}
		}
	}
	for(auto p:vii[v]){
		int a = p.first ,c = p.second;
		if(a == fa)continue;
		dfs2(a,v,c);
	}
}
void inp(){
	int n;if(!~scanf("%d",&n))exit(0);
	for(int i = 0;i<=n;i++)vii[i].clear();
	for(int i = 2;i<=n;i++){
		int a = i,b,c;scanf("%d%d",&b,&c);
#define vpush(a,b,c) vii[a].push_back(P(b,c));
		vpush(a,b,c);
		vpush(b,a,c);
	}
	dfs1(1,-1);
	dfs2(1,-1, 0);
	for(int i = 1;i<=n;i++){
		printf("%d\n", Mf[i]);
	}
}
//hdu2196.cc by xsthunder at Wed Jul 26 21:59:17 2017

//AC at Wed Jul 26 22:29:33 2017
 
