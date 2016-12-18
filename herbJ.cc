//本体打表
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
const int MAXN=1e6;
int prime[MAXN];
bool is_prime[MAXN];
int revprime[MAXN]; 
int cnt=0;
int revcnt=0;
int max_prime=0;

void Prime(){
	fill(is_prime,is_prime+MAXN,1);
	is_prime[0]=0;
	is_prime[1]=0;
	for(int i=2;i<MAXN;i++){
		if(is_prime[i]){
			prime[++cnt]=i;
			for(ll j=2;j*i<MAXN;j++){
				
				is_prime[j*i]=0;
			}
		}
	}
//	pA(is_prime,100);
}
int rev(int x){
	int l;
	int ans;

	while(x){
		ans*=10;
		l=x%10;
		x/=10;
		ans+=l;
	}
	return ans;
}

void sol(){
	Prime();
//	pA(prime,100);
//return ;
	printf("cnt:%d\n",cnt);
	max_prime=MAXN;
	for(int i=1;i<10000;i++){
		int cur=prime[i];
		int revcur=rev(cur);
		printf("revcur:%d ;cur %d\n",revcur,cur);
		printf("cur:%d revcur:%d\n", cur,revcur);
		//printf("i : %d ; cur: %d ;revcur :%d ;\n", i,cur,revcur);
		if(revcur<MAXN&&cur!=revcur&&is_prime[revcur]){
			printf("revcur:%d ;cur %d\n",revcur,cur);
			revprime[++revcnt]=cur;
		}
	}
//	printf("revcnt:%d\n", revcnt);
}
void print(){
	for(int i=1;i<=1000;i++){
		printf("%d,\n",revprime[i]);
	}
}
int main()
{
//	int n;
//	while(scanf("%d",&n)!=EOF){
//		printf("%d \n", rev(n));
//	}
	sol();
	print();
	return 0;
}
//herbJ.cc
//generated automatically at Sat Dec 10 11:46:18 2016
//by xsthunder

