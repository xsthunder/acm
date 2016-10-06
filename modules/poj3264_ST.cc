const bool test=0;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
int n,q;
int _n;
int A[17+1][1<<17];
int I[17+1][1<<17];
int _k;
void init(){
	_n=1;
	_k=0;
	while(_n<n){_n*=2;
		_k++;
	}
	int i=1;
	for(i=1;i<=n;i++){
		int tmp;scanf("%d",&tmp);
		A[0][i]=I[0][i]=tmp;
	}
	for(;i<=_n;i++){
		A[0][i]=-1;
		I[0][i]=inf;
	}
}
void Bui(){
	IF cout<<n<<','<<_n<<endl;
	IF cout<<q<<endl;
	IF cout<<_k<<endl;
	IF pA(A[0],n);
	IF pA(I[0],n);
	for(int i=1;i<=_k;i++){
		for(int k=1;k<=_n;k++){
			A[i][k]=max(A[i-1][k],A[i-1][k+(1<<(i-1))]);
			I[i][k]=min(I[i-1][k],I[i-1][k+(1<<(i-1))]);
			IF printf("%d,%d ",i,k);
			IF cout<<k+(1<<(i-1))<<'|';
			IF cout<<A[i][k]<<' '<<I[i][k]<<endl;
		}
	}
}
void Que(){
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		if (a==b){
			printf("%d\n",0);
			continue;
		}
		int k=log2(b-a);
		IF cout<<a<<','<<b<<' '<<k<<endl;
		int _max=max(A[k][a],A[k][b-(1<<k)+1]);
		int _min=min(I[k][a],I[k][b-(1<<k)+1]);
		IF cout<<_max<<'-'<<_min<<'=';
		printf("%d\n",_max-_min);
	}
}
void sol(){
	scanf("%d%d",&n,&q);
	init();
	Bui();
	Que();
}
int main()
{
	sol();
	return 0;
}
//poj3264_ST.cc
//generated automatically at Thu Oct  6 19:58:34 2016
//by xsthunder

//AC at Thu Oct  6 21:53:29 2016
 
