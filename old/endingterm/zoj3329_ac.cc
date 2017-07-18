#include<cstring>
#include<iostream>
#include<utility>
#include<cstdio>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)inp();
	return 0;
}
const int N = 1e6;
double dp[N];
const int K  = 40;
int pcnt[K];
double p[K];
double a[N];
double b[N];
int n,k1,k2,k3;
int MXK;
void cnt (){
	MS(a),MS(b);
	for(int i=n;i>=0;i--){
		a[i]+=p[0];
		for(int k=1;k<=MXK;k++){
			a[i]+=p[k]*a[i+k];
		}
	}
	for(int i=n;i>=0;i--){
		b[i]+=1;
		for(int k=1;k<=MXK;k++){
			b[i]+=p[k]*b[i+k];
		}
	}
//	pA(p,10,8);
//	pA(a,10,8);
//	pA(b,10,8);
	printf("%.15lf\n",(b[0]/(1-a[0])));
}
void inp(){
	int a,b,c;
	cin>>n>>k1>>k2>>k3>>a>>b>>c;
	MS(pcnt);
	MS(p);
	MXK=k1+k2+k3;
	for(int i=1;i<=k1;i++){
		for(int j=1;j<=k2;j++){
			for(int k=1;k<=k3;k++){
				if(i==a&&j==b&&k==c)pcnt[0]=1;
				else pcnt[i+j+k]++;
			}
		}
	}
	for(int i =0;i<=MXK;i++){
		p[i]=pcnt[i]/double (k1*k2*k3);
	}
	cnt();
}
//zoj3329.cc by xsthunder at Fri Jun 16 10:49:05 2017

//AC at Sun Jun 18 10:35:13 2017
 
