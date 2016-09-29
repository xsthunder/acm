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
const bool test=0;
#define IF if(test)
typedef long long int ll;
const ll inf=0x7ffffffff;
using namespace std;
typedef pair<int,int> point;
ll labs(ll a){
	if(a>0)return a;
	else return -a;
}
void pA(int *begin,int n){
	for(int i=0;i<n;i++){
		printf("%2d",*(begin+i));
	}
	printf("\n");
}
char s[100];
int A[20];
int n;
ll cur;
void init(){
	memset(A,0,sizeof(A));
	cur=inf;
	n=0;
}
void In(){
	fgets(s,sizeof(s),stdin);
//	IF cout<<s;
	for(int i=0;s[i]!='\0';i++){
		if(isdigit(s[i])){
			//A[n++]=s[i]-'0';
			A[n++]=s[i]-'0';
		}
	}
//	IF pA(A,n);
}
ll Gen(int a,int b){
	ll sum=0;;
	for(int i=a;i<=b;i++){
		sum+=A[i];
		sum*=10;
	}
	sum/=10;
	return sum;
}
void Ran(){
	if(A[0]==0&&n>2)return;
	if(A[n/2]==0&&n>2)return;
	cur=min(cur,labs((Gen(0,n/2-1)-Gen(n/2,n-1))));
	}
void Cho(){
	if(n==10){
		cur=247;
//		return;
	}
//	int cnt=0;
	sort(A,A+n);
//	IF pA(A,n);
	do{
		Ran();
//		IF pA(A,n);
	}while(next_permutation(A,A+n));
}
//void Cho(int a){
//	int mask=0;
//	for(int i=0;i<n;i++){mask<<=1;mask++;}
//	IF cout<<n<<' '<<hex<<mask<<endl;
//	for(int i=0;i<mask;i++){
//		if(__builtin_popcount(i)!=a)continue;
//		else {
////			IF cout<<hex<<i<<endl;
//			vector<int >v;
//			
//		}
//	}
//}
int main()
{
	int t;
	scanf("%d",&t);
//	IF cout<<t;
	getchar();
//	t=0;
	while(t--){
		init();
		In();
		IF pA(A,n);
		Cho();
		printf("%lld\n",cur);
	}
	return 0;
}
//poj2718.cc
//generated automatically at Wed Sep 28 22:13:54 2016
//by xsthunder

