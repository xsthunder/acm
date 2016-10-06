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
const bool test=1;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin+i)<<' '; } printf("\n"); }
const int N=1e5+10;
int A[2*N+1];//default -1
unsigned int I[2*N+1];//default -1 = 1>>32
int dat[N];
int n,q;
int _n;
int k;
void init(){
	memset(A,-1,sizeof(A));
	memset(I,-1,sizeof(I));
	//extend to 2^n;
	_n=1;
	while(_n<n)_n*=2;
	k=_n-2+1;
	//mark leaves
	for(int i=0;i<n;i++){
		A[i+k]=I[k+i]=dat[i];
		IF cout<<i+k;
	}
}
void Inp(){
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		dat[i]=tmp;
	}
}
void BA(){
	for(int i=_n-2;i>=0;i--){
		IF cout<<i<<' ';
		A[i]=max(A[2*i+1],A[2*i+2]);
		IF cout<<A[i]<<' '<<A[2*i+1]<<' '<<A[2*i+2]<<endl;;
		I[i]=min(I[2*i+1],I[2*i+2]);
	}
}
int QI(int a,int b,int k,int l,int r){
	IF cout<<a<<' ' <<b<<' '<<k<<' '<<l<<' '<<r<<endl;
	if(r<=a||b<=l)return inf;
	if(a<=l&&r<=b)return I[k];
	else {
		int vl=QI(a,b,k*2+1,l,(l+r)/2);
		cout<<vl<<endl;;
		int vr=QI(a,b,k*2+2,(l+r)/2,r);
		cout<<' '<<vr<<endl;;
		return min(vl,vr);
	}
}
int QA(int a,int b,int k,int l,int r){
	//IF cout<<a<<' ' <<b<<' '<<k<<' '<<l<<' '<<r<<endl;
	if(r<=a||b<=l)return -1;
	if(a<=l&&r<=b)return A[k];
	else {
		int vl=QA(a,b,k*2+1,l,(l+r)/2);
		int vr=QA(a,b,k*2+2,(l+r)/2,r);
		return max(vl,vr);
	}
}
int Q(int a,int b,int k,int l,int r){
	return QA(a,b,k,l,r)-QI(a,b,k,l,r);
}
void Out(){
	while(q--){
		int a,b;
		scanf("%d%d", &a,&b);
		IF cout<<a<<' '<<b<<endl;
		FI printf("%d\n", Q(a,b,0,0,n));
		IF printf("A %d, I %d\n", QA(a-1,b,0,0,n),QI(a-1,b,0,0,n));
	}
}
void sol(){
	while(scanf("%d%d",&n,&q)==2){
		Inp();
		init();
		BA();
		Out();
	}
}
template <typename T>
void pT(T *A, int d){//d for depth
	int sum=0;
	cout<<"------tree starts\n";
	for(int i=0;i<d;i++){
		cout<<i+1<<':';
		for(int k=i;k<d;k++){
			cout<<"    ";
		}
		for(int j=0;j<1<<i;j++){
			cout.width(4);
			cout<<*(A+sum++);
		for(int k=i;k<d-1;k++){
			cout<<"   ";
		}
		}
		cout<<endl;
	}
	cout<<"------tree ends\n";
}
int main()
{
	FI sol();
	IF {
		scanf("%d%d",&n,&q);
		Inp();
		init();
		BA();
		Out();
		//pT(A,4);
		//pT(I,4);
//		pA(dat,n);
//		pA(A,_n-1);
//		pA(I,_n-1);
	}
	return 0;
}
//poj3264.cc
//generated automatically at Thu Oct  6 11:21:56 2016
//by xsthunder

