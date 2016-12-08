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

const int N=1e6;
int Cnt[N];
int Ai[N];

void sol(){
	int n,x;
	scanf("%d%d",&n,&x);
	ll ans=0;
	for(int i=0;i<n;i++){
		int ai;
		scanf("%d", &ai);
		Cnt[ai]++;
		Ai[i]=ai;
	}
	for(int i=0;i<n;i++){
		int pre=x^Ai[i];
		if(!x){
			ans+=Cnt[pre]-1;
		}
		else {
			ans+=Cnt[pre];
		}
	}
	ans/=2;
	//printf("Cnt:");pA(Cnt,9);
	//printf("pA:");pA(Ai,9);
	cout<<ans<<endl;
}
int main()
{
	sol();
	return 0;
}
//b.cc
//generated automatically at Wed Dec  7 10:02:10 2016
//by xsthunder

//AC at Wed Dec  7 11:10:56 2016
 
