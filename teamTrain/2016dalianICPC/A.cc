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
const int N = 2e3;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
int p[N];
int ran[N];
int findp(int a){
	if(p[a]<0)return a;
	else return p[a]=findp(p[a]);
}
void inter(int a,int b){
	//if(ran[a]<ran[b])swap(a,b);
	ran[a]+=ran[b];
	p[b]=a;
}
void inp(){
	int n,m,x,y;
	if(!(cin>>n>>m>>x>>y))exit(0);
	memset(p,-1,sizeof(p));
	memset(ran,0,sizeof(ran));
	for(int i =0;i<N;i++){
		ran[i]=1;
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		a = findp(a);
		b =findp(b);
		if(a!=b)inter(a,b);
		//pA(p,6,3);
	}
	while(x--){
		int a;
		cin>>a;
		a=findp(a);
		p[a]=-3;
	}
	while(y--){
		int a;
		cin>>a;
		a=findp(a);
		p[a]=-4;
	}
	int cnt =0;
	for(int i =1;i<=n;i++){
		if(p[i]==-1&&ran[i]==1){
			cnt++;
		}
	}
	if(cnt>0)cout<<"NO\n";
	else cout<<"YES"<<endl;
}
//A.cc by xsthunder at Thu May 25 10:27:55 2017

