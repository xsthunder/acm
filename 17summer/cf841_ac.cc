#include<cstdio>
#include<queue>
#include<cassert>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define all(z) ((z).begin()),((z).end())
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
int n,w,h;
const int N= 100000+1000;
const int N2= N*2;
typedef vector<int> vec;
vec ve[N2];
int p[N],t[N],g[N];
int ansx[N],ansy[N];
vec xs,ys;
void inp(){
	scanf("%d%d%d",&n,&w,&h);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&g[i],&p[i],&t[i]);
		//grouping 
		ve[p[i]-t[i]+N].push_back(i);
	}
	for(int I=0;I<N2;I++){
		xs.clear(),ys.clear();
		if(ve[I].empty())continue;
		for(int x:ve[I]){
			if(g[x]==1)xs.push_back(p[x]);
			else ys.push_back(p[x]);
#ifdef XS
//			printf("%d %d\n",I,x);
#endif
		}
		sort(all(xs));
		sort(all(ys),greater<int>());
		sort(all(ve[I]),[](int u,int v){
				if(g[u]!=g[v])return g[u]==2;
				else return (g[u]==2)?p[u]>p[v]:p[u]<p[v];
				});
		for(int x:ve[I]){
#ifdef XS
		//	printf("%d %d\n",I,x);
#endif
		}
		int cnt=0;
		for(int x:xs){
#ifdef XS
		//	printf("xs %d\n",x);
#endif
			ansx[ve[I][cnt]]=x;
			ansy[ve[I][cnt]]=h;
			cnt++;
		}
		for(int x:ys){
#ifdef XS
		//	printf("ys %d\n",x);
#endif
			ansx[ve[I][cnt]]=w;
			ansy[ve[I][cnt]]=x;
			cnt++;
		}
		assert(cnt==ve[I].size());
	}
	for(int i=0;i<n;i++){
		printf("%d %d\n",ansx[i],ansy[i]);
	}

}
//cf841.cc by xsthunder at Tue Sep  5 09:26:32 2017

//AC at Tue Sep  5 10:23:04 2017
 
