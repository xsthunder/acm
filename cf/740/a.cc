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
typedef pair<ll,ll> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
void sol(){
	ll P[4];
	const int MOD =4;
	int n;

	for(int i=0;i<4;i++){
		cin>>P[i];
	}
	n=P[0];
	n%=MOD;
	priority_queue< point ,vector<point> , greater<point>  >q;
	if((n^1)==0){
		q.emplace(P[3],(n+3)%MOD);
		q.emplace(P[1],(n+1)%MOD);
	}
	else q.emplace(0,n);
	ll money=0;
	ll books=0;
	while(!q.empty()){
		point cur=q.top();
		q.pop();
		money=cur.first;
		books=cur.second;
		if(books==0)break;
		for(int i=1;i<4;i++){
			q.emplace(money+P[i],(books+i)%MOD);
		}
	}
	cout<<money<<endl;
}
int main()
{
	sol();
	return 0;
}
//a.cc
//generated automatically at Wed Dec  7 11:37:00 2016
//by xsthunder

