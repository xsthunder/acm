#include<iostream>
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
using namespace std;
#define MS(x) memset(x, 0 ,sizeof(x)) 
#define SC(x) scanf("%d", & (x) )
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int inf=0x7fffffff;
typedef long long int lld;
typedef long long unsigned llu;
typedef pair <int ,int > point;
const int N=120+10;
point P[N];
int D[N];
int n;
int solve(int i){
	if(i==n-1)return D[i]=1;
	if(D[i]>0)return D[i];
	int best=1;
	point next,cur;
	cur=P[i];
	rep(j,i+1,n-1){;
		next=P[j];
		if(cur.first<=next.second)best=max(best,solve(j)+1);
	}
//	rep(j,0,n-1){
//		cout<<j<<' '<<D[j]<<endl;
//	}
//	cout<<"--------"<<endl;
	return D[i]=best;
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(SC(n)!=EOF){
		MS(D);MS(P);
		int x,y;
		int _max,_min;
		rep(i,0,n-1){ SC(x);SC(y);
		_max=max(x,y);
		_min=min(x,y);
		P[i]=make_pair(_max,_min);
		}
		sort(P,P+n);
//		rep(i,0,n-1) cout<<P[i].first<<' ' <<P[i].second<<endl;
		int best=0;
		rep(i,0,n-1){
			best=max(solve(i),best);
		}
//		rep(j,0,n-1){ cout<<j<<' '<<D[j]<<endl; }
		cout<<n-best<<endl;
	//	break;

	}
	

	
	//insert code
	return 0;
}
//8-3a.cc

//AC

