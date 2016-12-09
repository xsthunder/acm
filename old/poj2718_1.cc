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
const int inf=0x7fffffff;
#define IF if(test)
bool test=1;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%d" ,*(begin+i));
	}
	printf("\n");
}
char s[100];
int A[20];
int n;
ll ans;
void ini(){
	n=0;
	ans=inf;
}
void inp(){
	fgets(s,sizeof(s),stdin);
	for(int i=0;s[i]!='\0';i++){
		if(isdigit(s[i])){
			A[n++]=s[i]-'0';
		}
	}
}
ll ran(int a,int b){
	ll sum=0;
	for(int i=a;i<=b;i++){
		sum*=10;
		sum+=A[i];
	}
	return sum;
}
ll per(){
	sort(A,A+n);
	if(n==2){
		return llabs(A[0]-A[1]);
	}
	do{
		if(n==3){
			if(A[0]==0)continue;
			else {
				ans=min(ans,llabs(ran(0,1)-ran(2,2)));
//				cout<<ran(0,1)<< ' '<<ran(2,2)<<endl;;;
			}
		}
		else {
			int a=(n-1)/2;
			int b=(n-1)/2+1;
			if(A[0]==0||A[b]==0)continue;
			else {
				ans=min(ans,llabs(ran(0,a)-ran(b,n-1)));
			}
		}
	}while(next_permutation(A,A+n));
	return ans;
}
void sol(){
	int t;
	while(scanf("%d",&t)!=EOF){
		getchar();//erase ending endl
		while(t--){
		ini();
		inp();
//		pA(A,n);
		printf("%lld\n",per());
		}
	}
}
int main()
{
	sol();
	test=0;
	IF {
		while(!cin.eof()){
			ini();
			inp();
			cout<<ran(0,n-1)<<endl;;
		}
	}
	return 0;
}
//poj2718_1.cc
//generated automatically at Fri Sep 30 09:49:40 2016
//by xsthunder

