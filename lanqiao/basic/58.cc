const bool TEST=0;
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
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
int m;
struct M{
	int num[40][40];
	M(){
		memset(num,0,sizeof(num));
	}
}e;
void pri(M A){
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			printf("%d ", A.num[i][j]);
		}
		cout<<endl;
	}
}
M mul(M a,M b){
	M c;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<m;k++){
				c.num[i][j]+=a.num[i][k]*b.num[k][j];
			}
		}
	}
	return c;
}
M multi(M c ,int n){
	M b=c,r=e;
	while(n){
		IF cout<<n<<endl;
		IF pri(r);
		if(n&1)r=mul(r,b);
		b=mul(b,b);
		n>>=1;
	}
	return r;
}
void sol(){
	int n;
	M A;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		e.num[i][i]=1;
		for(int j=0;j<m;j++){
			scanf("%d", &A.num[i][j]);
		}
	}
	IF pri(mul(e,e));
	A=multi(A, n);
	pri(A);
}
int main()
{
	sol();
	return 0;
}
//58.cc
//generated automatically at Wed Jan 18 16:45:30 2017
//by xsthunder

