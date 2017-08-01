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
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 51;
void inp(){
	ll n,sum,A[N];cin>>n;
	for(int i = 1;i<=n;i++)cin>>A[i];
	ll k = 0;
	while(1){
		sum = 0;
		for(int i = 1;i<=n;i++)sum += A[i]/n;
		if(!sum)break;
		k += sum;
		for(int i = 1;i<=n;i++){
			A[i] = sum - A[i]/n + A[i]%n;
		}
	}
	cout<<k<<endl;
}
//at79E.cc by xsthunder at Sun Jul 30 16:12:38 2017

//AC at Sun Jul 30 16:19:46 2017
 
