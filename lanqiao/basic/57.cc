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
void pA(T *begin,int n){ cout<<n<<endl;for(int i=0;i<n;i++){ cout<<*(begin++)<<' '; } printf("\n"); }
const int to = 1e4+100;
int cnt;
int pri[2000];
bool isPri[to];
void prime(){
	fill (isPri,isPri+to,1);
	cnt=0;
	for(int i=2;i<to;i++){
		if(isPri[i]){
			pri[cnt++]=i;
			for(int j=i;j<to;j+=i){
				isPri[j]=0;
			}
		}
	}
}
void bfs(int a,bool fflag ){
	if(a==1)return;
	for(int i=0;i<cnt;i++){
		if(a<pri[i])break;
		if(a%pri[i]==0){
			if(fflag)cout<<'*';
			cout<<pri[i];
			bfs(a/pri[i],1);
			return ;
		}
	}
	return ;
}
void sol(){
	prime();
	//pA(pri,cnt);
	int a,b;
	scanf("%d%d",&a,&b);
	for(;a<=b;a++){
		cout<<a<<'=';
		bfs(a,0);
		cout<<endl;
	}

}
int main()
{
	sol();
	return 0;
}
//57.cc
//generated automatically at Wed Jan 18 11:14:52 2017
//by xsthunder

