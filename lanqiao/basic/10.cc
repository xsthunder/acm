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
int A[100];
void sol(){
	int n;
	A[1]=1;
	scanf("%d",&n);
	int old=0,old2=0;;
	for(int i=1;i<=n;i++){
		old=0;
		for(int j=1;j<=i;j++){
			if(j!=1)cout<<' ';
			cout<<A[j];
			old2=A[j];
			A[j]=old+A[j];
			old=old2;
		}
		A[i+1]=1;
		cout<<endl;
	}
}
int main()
{
	sol();
	return 0;
}
//10.cc
//generated automatically at Tue Jan 17 13:37:31 2017
//by xsthunder

