const bool TEST=1;
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
#include<sstream>
#include<stack>
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
void sol(){
	int n ; 
	int c= 0;
	bool flagc=1;
	bool flag=1;
	cin>>n;
	if(n==1){
		flag=0;
	}
	for(int i = 1; i<=n;i++){
		int x ;
		scanf("%d", &x);
		if(x!=i)flag=0;
		if(!c)c=x;
		else {
			if(c!=x){
				flagc=0;
			}
		}
	}
	if(flag){
		cout<<n<<endl;
		for(int i = 1;i<=n;i++){
			if(i!=1)cout<<' ';
			cout<<i;
		}
		cout<<endl;
		for(int i = 1;i<=n;i++){
			if(i!=1)cout<<' ';
			cout<<i;
		}
		cout<<endl;
	}
	else if(flagc){
		cout<<1<<endl;
		for(int i = 1;i<=n;i++){
			if(i!=1)cout<<' ';
			cout<<1;
		}
		cout<<endl;
		cout<<c<<endl;
	}
	else cout<<-1<<endl;
}
int main()
{
	sol();
	return 0;
}
//D.cc
//generated automatically at Tue Feb 14 17:21:56 2017
//by xsthunder

