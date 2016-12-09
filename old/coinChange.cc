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

int coinChange(vector<int> coins,int amount){
	if(amount==0)return 0;
	vector<int > d;
	int size=amount+1;;
	for(auto it =coins.begin();it!=coins.end();it++){
		size+=*it;
	}
	d.resize(size);
	for(auto it =coins.begin();it!=coins.end();it++){
		d[*it]=1;
	}
	for(int i=0;;i++){
		if(i>=amount)break;
		if(d[i]>0){
		for(auto it =coins.begin();it!=coins.end();it++){
			if(i+*it>=size)continue;
			if(d[i+*it]==0)d[i+*it]=d[i]+1;
		}
		}
	}
	return !d[amount]?-1:d[amount];

}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	vector<int> coins={2147483647};
	int amount=2;
	cout<<coinChange(coins,amount)<<endl;;

	
	//insert code
	return 0;
}
//coinChange.cc

