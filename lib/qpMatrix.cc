#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("qpMatrix.in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
namespace qpMatrix{
	const int D = 2;
	typedef ll M[D][D];
	ll mod = 1024;
#define MCP(x,y) memcpy(x,y,sizeof(M)) //x=y
	void pM(M m){
		for(int i =0;i<D;i++){
			for(int j=0;j<D;j++){
				printf("%lld ",m[i][j]);
			}
			putchar('\n');
		}
	}
	void MtM(M m,M a,M b){//m=a*b
		M ans={0};
		for(int i=0;i<D;i++){
			for(int j =0;j<D;j++){
				for(int k=0;k<D;k++){
					ans[i][j]+=a[i][k]*b[k][j]%mod;
				}
			}
		}
		MCP(m,ans);
	}
	void qp(M m,ll p){
		M b={0};for(int i = 0;i<D;i++)b[i][i]=1;
		while(p){
			if(p&1)MtM(b,b,m);
			p>>=1;
			MtM(m,m,m);
		}
		MCP(m,b);
	}
}
void inp(){
	using namespace qpMatrix;
	int a,b,n;if(scanf("%d%d%d%lld",&a,&b,&n,&mod)==EOF)exit(0);
	M A0={
		0,a,
		0,1
	};
	M A={
		a,b,
		1,a
	};
	qp(A,n-1);
	MtM(A,A,A0);
	printf("%lld\n",(2*A[0][1])%mod);
}
//qpMatrix.cc by xsthunder at Wed Aug 23 16:21:51 2017

