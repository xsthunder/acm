#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
const int D = 2;
typedef ll M[D][D];
ll mod;
#define log(x) debug(x,#x)
void debug(M a,string s=""){
#ifdef XS
	printf("M %s vvvvv\n",s.c_str());
	for(int i=0;i<D;i++){
		for(int j=0;j<D;j++){
			if(j)putchar(' ');
			printf("%lld",a[i][j]);
		}
		putchar('\n');
	}
	fflush(stdout);
#endif
}
void de(M a){
#ifdef XS
	for(int i=0;i<D;i++){
		for(int j=0;j<D;j++){
			if(j)putchar(' ');
			printf("%lld",a[i][j]);
		}
		putchar('\n');
	}
	fflush(stdout);
#endif
}
int main(){
#ifdef XS
	freopen("hdu1588.in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
ll k,b,n;
void MtM(M ans,M a,M b){
	M tmp={0};
	for(int i =0;i<D;i++){
		for(int j=0;j<D;j++){
			for(int k=0;k<D;k++){
				tmp[i][j]+=a[i][k]*b[k][j];
				tmp[i][j]%=mod;
			}
//			log(tmp);
		}
	}
#define cp(d,f) memcpy((d),(f),sizeof(M))//d=f
	cp(ans,tmp);
}
void qp(M x,ll p){
	M tmp={0};for(int i = 0;i<D;i++)tmp[i][i]=1;
	while(p){
		if(p&1) MtM(tmp,tmp,x);//b=b*x 
		MtM(x,x,x);
		p>>=1;
	}
	cp(x,tmp);
}
M I={
	1,0,
	0,1
};
void MpM(M ans,M a,M b){
	M tmp={0};
	for(int i=0;i<D;i++){
		for(int j =0;j<D;j++){
			tmp[i][j]=(a[i][j]+b[i][j])%mod;
		}
	}
	cp(ans,tmp);
}
void rec(M ans,M K0,ll n){
	M K;cp(K,K0);
	M tmp={0};
	if(n==0){cp(ans,tmp);return;}
	if(n==1){for(int i =0;i<D;i++)tmp[i][i]=1;cp(ans,tmp);return;}
	if(n&1){
		cp(tmp,K);
		qp(tmp,n-1);
		n--;
	}
	M s={0};rec(s,K,n/2);
	M f={0};cp(f,K),qp(f,n/2);
	MpM(f,f,I);
	MtM(f,f,s);
	MpM(tmp,tmp,f);
	cp(ans,tmp);
}
void inp(){
	if(scanf("%lld%lld%lld%lld",&k,&b,&n,&mod)==EOF)exit(0);
	M B0={
		0,0,
		0,1
	};
	M B={
		0,1,
		1,1
	};
	if(b==0){
		n--;b=k;
	}
	if(n<=0){
		puts("0");
		return;
	}
	qp(B,b-1);
	MtM(B0,B,B0);
	log(B0);
	M K={
		0,1,
		1,1
	};qp(K,k);
	log(K);
	M ans={0};
	rec(ans,K,n);
	log(ans);
	MtM(ans,ans,B0);
	printf("%lld\n",ans[1][1]);
	log(ans);
//	exit(0);
}
//hdu1588.cc by xsthunder at Tue Aug 29 21:50:14 2017

//AC at Wed Aug 30 08:35:32 2017
 
