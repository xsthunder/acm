#include<iostream>
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
const int N  = 1e4;
int n;
int ran[N];
int p[N];
int fp(int a){
	if(p[a]==-1)return a;
	else return p[a]=fp(p[a]);
}
void inter(int a,int b){
	if(a==b)return ;
	else {
		if(ran[a]<ran[b])swap(a,b);
		p[b]=a;
		ran[a]+=ran[b];
	}
}
void inp(){
	int m;
	if(!(cin>>n>>m))exit(0);
	for(int  i=0;i<=n;i++){
		ran[i]=1;
		p[i]=-1;
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		a= fp(a);
		b=fp(b);
		inter(a,b);
	}
	int flag=1;
	for(int i =1;i<=n;i++){
		if(p[i]==-1){
			if(ran[i]%3){
				flag=0;
				break;
			}
		}
	}
//	pA(p,n,3);
	cout<<(flag?"Yes":"No")<<endl;
}
//B.cc by xsthunder at Fri May 26 09:48:12 2017

//AC at Fri May 26 09:55:17 2017
 
