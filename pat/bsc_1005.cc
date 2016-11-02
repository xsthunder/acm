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
int nxt(int x){
	if(x==1)return 1;
	if(x%2==0)return x/2;
	else return (3*x+1)/2;
}
int A[5000];
void fnd(int f){
	if(f==1) {A[f]=0;return ;}
	int x=f;
	if(A[x]!=-1){
		return;
	}
	else {
		A[f]=0;
		do{
			x=nxt(x);
			if(A[x]==-1){
				A[x]=f;
			}
			else if(A[x]==0){
				A[x]=f;
				return ;
			}
			else {
				return ;
			}
		}while(x!=1);
	}
}
void sol(){
	memset(A,-1,sizeof(A));
	int t;
	scanf("%d",&t);
	while(t--){
		int x;scanf("%d",&x);
		fnd(x);
	}
	set<int >s;
	for(int i=1;i<5000;i++){
		if(A[i]==0)s.insert(i);
	}
	for(auto it=s.rbegin();it!=s.rend();it++){
		if(it==s.rbegin())printf("%d",*it);
		else printf(" %d",*it);
	}
	printf("\n");
}
void fmax(){//5000;
	int maxn=0;
	for(int i=1;i<=100;i++){
		int x=i;
		while(x!=1){
			x=nxt(x);
			maxn=max(x,maxn);
		}
		maxn=max(x,maxn);
	}
	cout<<maxn<<endl;
}
int main()
{
	sol();
	//fmax();
	return 0;
}
//bsc_1005.cc
//generated automatically at Tue Nov  1 20:43:58 2016
//by xsthunder

