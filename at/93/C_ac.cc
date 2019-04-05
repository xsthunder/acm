#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 1e5 + 100;
int A[N];
int B[N];
int C[N];
int D[N];
void pA(int *a, int n){
	for(int i =0 ;i<n;i++)printf("%d ", a[i]);
	printf("\n");
}
void inp(){
	int n;scanf("%d",&n);
	for(int i = 0;i<n;i++)scanf("%d",&A[i]);
	B[0] = 0;
	for(int i = 1;i<=n;i++)B[i] = A[i - 1];
	B[n+1] = 0;
	n += 2;
	for(int i = 0;i<n - 1;i++)C[i] = abs(B[i + 1] - B[ i ]);
	D[0] = C[0];
	for(int i = 1;i<n - 1;i++)D[i] = D[i-1] + C[i];
//	pA(C,n);
//	pA(D,n);
//
	int ans,a,b,c;
	for(int i = 1;i<n-1;i++){
		a = (i-2>=0)?D[i - 2]:0;
		b =  D[n-2] - D[ i];
		c = abs(B[i + 1] - B[i-1]);
		//printf("f %d e %d  m %d\n", a,b,c);
		ans = a+b+c;
		printf("%d\n",ans);
	}
}
//C.cc by xsthunder at Sun Mar 25 20:00:09 2018

//AC at Sun Mar 25 20:22:21 2018
 
