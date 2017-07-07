#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	#include<cassert>
	#define NDEBUG
	const int Te=1;
#else 
	const int Te=0;
#endif
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<limits>
#include<cmath>
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
		int n;
		scanf("%d", &n);
		for(int i = 1;i<=n;i++){
			printf("Case %d: ",i);
			inp();
			printf("\n");
		}
	return 0;
}
char imp[20]="impossible";
const int N = 1e4+1e3;
vector<int > v[N];
double eps =numeric_limits<double>::epsilon();
double k[N],e[N];
double A[N],B[N],C[N];
#define equ(a,b) (fabs(a-b)<=eps)
bool sea(int i,int fa){
	if(v[i].size()==1&&fa!=-1){
		A[i]=k[i];
		B[i]=C[i]=1.0-k[i]-e[i];
		return true;
	}
	double sumA,sumB,sumC;
	sumA=sumB=sumC=0;
	for(int j : v[i]){
		if(j==fa)continue;
		if(sea(j,i)){
			sumA+=A[j];
			sumB+=B[j];
			sumC+=C[j];
		}
		else return false;
	}
	double p = (1.0-k[i]-e[i]);
	int m = (v[i].size());
	double deno = 1-p*sumB/m ;
	if(equ(deno,0.0))return false;
	A[i]=(k[i]+p*sumA/m)/(deno);
	B[i]=(p/m)/(deno);
	C[i]=(p*sumC/m+p)/(deno);
	return true;
}
void inp(){
	int n;
	scanf("%d",&n);
	MS(A);MS(B);MS(C);MS(k);MS(e);
	for(int i =0;i<=n;i++){
		v[i].clear();
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
#define push(a,b) v[a].push_back(b)
		push(a,b);
		push(b,a);
	}
	for(int i =1;i<=n;i++){
		double a,b;
		scanf("%lf%lf",&a,&b);
		k[i]=a/100.0;
		e[i]=b/100.0;
	}
	if(sea(1,-1)&&!equ(A[1],1.0))printf("%.6lf",C[1]/(1.0-A[1]));
	else printf("%s",imp);
}
//hdu4035.cc by xsthunder at Fri Jul  7 10:05:26 2017

//AC at Fri Jul  7 15:15:04 2017
 
