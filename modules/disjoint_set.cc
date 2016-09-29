#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
using namespace std;
const int inf=0x7fffffff;
const int N=5e4+10;
int parent[N];
int offsetval[N];
void init(){
	for(int i=1;i<=N;i++){
		parent[i]=i;
	}
}
int cnv(int x){
	x%=3;
	switch (x){
		case 0:return 0;
		case 1:return 2;
		case 2:return 1;
		default:exit(1);
	}
}
int Find(int x){
	if(x==parent[x])return x;

	return Find(parent[x]);
}
int offset(int x,int y){
	if(parent[x]==y)return offsetval[x];
	else return offsetval[x]+offset(parent[x],Find(parent[x]));

}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n,k,d;
	scanf("%d%d",&n,&k);
	int ans=0;
	int x,y;
	init();
	while(k--){
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n)ans++;
		else if(x==y){
			if(d==1);
			else ans++;
		}
		
		else {
			int xfa,yfa;
			xfa=Find(x);
			yfa=Find(y);
			if(xfa==yfa){
				if(d-1==(offset(x,xfa)+cnv(offset(y,yfa)))%3);
				else ans++;
			}
			else{
				parent[xfa]=yfa;
				offsetval[xfa]=(cnv(offset(x,xfa))+d-1+offset(y,yfa))%3;
			}
		}
	}
	printf("%d\n",ans);
	//insert code
	return 0;
}
//poj1182.cc

//AC

