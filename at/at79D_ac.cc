#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	try{
		//while(1)
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 51;
const int n = 50;
ll A [N];
void inp(){
	MS(A);
	ll k;cin>>k;
	ll a0 = k/n;
	for(int i = 1;i<=n;i++)A[i] = a0 + i - 1;
	ll r = k%n;
	for(int i = 1;i<=r;i++){
		A[i] += n;
		for(int j = 1;j<=n;j++){
			if(i == j )continue;
			A[j] -= 1;
		}
	}
	//pA(A, n, "A");
	cout<<n<<endl;
	for(int i = 1;i<=n;i++){
		if(i)cout<<' ';
		cout<<A[i];
	}
}
//at79D.cc by xsthunder at Sun Jul 30 10:02:14 2017

//AC at Sun Jul 30 10:22:00 2017
 
