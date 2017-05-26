#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
const int N = 2e3;
int vis[N];
int c[N];
vector<int > v[N];
int flag=1;
void ds(int r,int f){ 
	if(!flag)return ;
	c[r]=f;
	for(U i=0;i<v[r].size();i++){
		int cur  = v[r][i];
		if(c[cur]==f)flag=0;
		if(!vis[cur]){
			vis[cur]=1;
			if(c[cur]<0){
				c[cur]=!f;
				ds(cur,!f);
			}
			else {
				if(c[cur]==f)flag=0;
			}
		}
	}
}
void inp(){
	int n,m,x,y;
	if(!(cin>>n>>m>>x>>y))exit(0);
	for(int i =0;i<N;i++){
		v[i].clear();
		c[i]=-1;
		vis[i]=0;
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	flag=1;
	while(x--){
		int a;
		cin>>a;
		if(c[a]<0){
			vis[a]=1;
			c[a]=1;
			ds(a,1);
			vis[a]=0;
		}
		else if(c[a]==0)flag=0;
	}
	while(y--){
		int b;
		cin>>b;
		if(c[b]<0)
		{
			vis[b]=1;
			c[b]=0;
			ds(b,0);
			vis[b]=0;
		}
		else if(c[b]==1){
			flag=0;
		}
	}
	//pA(c,6,3);
	if(flag)for(int i=1;i<=n;i++){
		if(v[i].size()==0&&c[i]<0)
			flag=0;
		else if(c[i]<0){
			vis[i]=1;
			ds(i,0);
			vis[i]=0;
		}
	}
	if(flag)cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}
//A3.cc by xsthunder at Thu May 25 11:58:36 2017

//AC at Thu May 25 20:46:42 2017
 
