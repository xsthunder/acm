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
const int N=1e4+10;
int d[N];
char s[N];
int n;
int solve(int x)
{
	if(d[x]>=0)return d[x];
	else 
	{
		int best=-2;
		for(int i=x+1;i<n;i++){
			if(s[x]<s[i]){ best=max(best,solve(i));}
		}
		if(best==-2)return d[x]=1;
		return d[x]=best+1;
	}
}

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		memset(d,-1,sizeof(d));
		scanf("%s",s);
		n=strlen(s);
		d[n-1]=1;
		int best=-2;
		for(int i=0;i<n;i++){
			best=max(best,solve(i));
		}
		printf("%d\n",best);
	}


	
	//insert code
	return 0;
}
//nyoj17.cc

//AC

