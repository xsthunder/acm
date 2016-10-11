const bool test=1;
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
template <typename T>
void pT(T *A, int d){//d for depth
	int sum=0;
	cout<<"------tree starts\n";
	for(int i=0;i<d;i++){
		cout<<i+1<<':';
		for(int j=0;j<1<<i;j++){
			cout<<*(A+sum++)<<' ';
		}
		cout<<endl;
	}
	cout<<"------tree ends\n";
}
const int N=1<<20;
int I[N];
int n,_n;
void init(){
	scanf("%d",&n);
	_n=1;
	while(_n<n)_n<<=1;
	for(int i=_n;i<2*_n+100;i++){
		I[i]=inf;
	}
}
void inp(){
	int k=_n-2+1;
//	IF cout<<"inping\n";
	for(int i=0;i<n;i++){
		scanf("%d",&I[i+k]);
//IF 		cout<<i<<n<<i+k<<' '<<I[i+k]<<endl;
	}
//	IF cout<<"end inping\n";
	//pT(I,3);
	for(int i=_n-2;i>=0;i--){
//IF 	cout<<i<<' '<<2*i+1<<' '<<2*i+2<<endl;
		I[i]=min(I[2*i+1],I[2*i+2]);
	}
}
int rmq(int l,int r,int k,int a,int b,int val){
IF printf("%d,%d,%d,%d,%d,%d\n",l,r,k,a,b,val);
	if(val<I[k])return inf;//quick start
	if(r<a||l>b)return inf;
	if(l>=a&&r<=b){
	if(b-a==1){
		if(I[k]<=val)return I[k];
		else return inf;
	}
	int valr,vall;
	vall=rmq(l,r,2*k+1,a,(a+b)/2,val);
	if(vall==inf){
		valr=rmq(l,r,2*k+2,(a+b)/2,b,val);
		return valr;
	}
	else {
		return vall;
	}
	}
}
void que(){
	int r,l;
	scanf("%d%d",&l,&r);
	int k=_n-2;
	int a=I[k+l];
	int b;
	//IF cout<<a<<endl;
	if(a!=0)
	if(r!=l)
		for(;;){
			b=rmq(l,r,0,0,_n,a);
IF cout<<a<<' '<<b<<endl;
			if(b==inf)break;
			if(b==0)break;
IF cout<<a<<' '<<b<<endl;
			a=a%b;
			if(a==0)break;

		} printf("%d\n",a); 
}
void sol(){
	int t;
	int q;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			init();
			inp();
			scanf("%d",&q);
			while(q--){
				que();

			}
		}
	}
}
int main()
{
	//sol();
	IF {
		init();
		inp();
		int a,b;
		
	int k=_n-2;
		while(scanf("%d%d",&a,&b)!=EOF){
			cout<<rmq(a,b,0,0,_n,I[k+a])<<endl;
		}
	}
	return 0;
}
//02.cc
//generated automatically at Tue Oct 11 15:50:00 2016
//by xsthunder

