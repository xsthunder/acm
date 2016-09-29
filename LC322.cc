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
int coinChange(vector<int>& coins, int amount) {
vector<int> d;
d.resize(amount+1);
int inf=0x7fffffff;
//for(auto it=d.begin();it!=d.end();it++)it;
d[0]=0;
	for(int i=1;i<=amount;i++)
	{
	    int t;
	    t=inf;
	    for(auto it=coins.begin();it!=coins.end();it++){
		t=min(t,d[(i-*it)>=0?d[i-*it]:-inf]);
	    }
	    d[i]=t<0?-inf:t+1;
	    for(auto it=d.begin();it!=d.end();it++){
		    cout<<"i: "<<*it<<endl;
}
}

return d[amount]>0?d[amount]:-1;
}

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	vector<int> coins={1,2,5};
	cout<<coinChange(coins,11);

	
	//insert code
	return 0;
}
//LC322.cc

