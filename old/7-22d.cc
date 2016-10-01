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
int col[300+10];
int clock(int x)
{
	return col%300;
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n,m;
	while(scanf("%d%d",&n,&m)){
		memset(col,0,sizeof(col));
		int A,B,X;
		scanf("%d%d%d",&A,&B,&X);
		col[1]=A;
		col[clock(1+X)]=B;
		m--;
		while(m--){
			scanf("%d%d%d",&A,&B,&X);
		}
			
		
	k

	
	//insert code
	return 0;
}
