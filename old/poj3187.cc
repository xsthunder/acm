#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<cassert>
#define IF if(test)
const int inf=0x7fffffff;
const bool test=0;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%d ",*(begin+i));
	}
}
int n;
ll sum;
int A[20];
int tmp[20];
bool Sum(){
	memcpy(tmp,A,sizeof(A));
	IF pA(tmp,n);
	//IF pA(A,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			tmp[j]=tmp[j]+tmp[j+1];
		}
	}
	if(tmp[0]==sum)return 1;
	else return 0;
}
void solve(){
	while(scanf("%d%lld",&n,&sum)!=EOF){
		for(int i=1;i<=n;i++){
			A[i-1]=i;
		}
//		pA(A,n);
//		pA(A,n);
		do{
//			IF break;
			if(Sum())break;
		}while(next_permutation(A,A+n));
		pA(A,n);
//		pA(A,n);
	}
}
int main()
{
	solve();
	return 0;
}
//poj3187.cc
//generated automatically at Thu Sep 29 21:38:08 2016
//by xsthunder

//AC at Thu Sep 29 22:01:46 2016
 
