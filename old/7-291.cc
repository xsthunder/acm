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
const int inf=0x7fffffff;
const int N=1e5;
int d[N+10];
int x,y;
int solve(int i){
	for(int j=0;j<=50;j++)cout<<j<<": "<<d[j];
	if(i<0||i>N)return inf;
	if(d[i]>0)return d[i];
	if(i==y)return d[y]=1;
	else {
		return d[i]=1+min(min(solve(i+1),solve(i-1)),solve(2*i));
	}
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(scanf("%d%d", &x,&y)!=EOF){
		memset (d,0,sizeof(d));
		printf("%d\n", solve(x));
	}

	
	//insert code
	return 0;
}
//7-291.cc

