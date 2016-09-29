//SgFuction by xsthunder
#include<algorithm>//for max_element
#include<set>
#include<cstdio>
using namespace std;
const int MAX_N=1000;
const int MAX_K=1000;
const int MAX_X=1000;
int N,K,X[MAX_N],A[MAX_K];
int SG[MAX_X+1]
void solve(){
	SG[0]=;
	int max_x=max_element(X,X+N);
	for(int j=1;j<=max_x;j++){
		set<int> s;
		for(int i=0;i<K;i++){
			if(A[i]<=j)s.insert(SG[j-A[i]]);
		}
		int g=0;
		while(s.count(g)!=0)g++;
		SG[j]=g;
	}
	int x=0;
	for(int i=0;i<N;i++)x^=SG[X[i]];
	puts(x==0?"the first win":"the second win");
}
