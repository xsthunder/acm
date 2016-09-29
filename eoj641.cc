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
const int N=3e5+100;
int c[N];
int s[N];
int d[N];
int t,cur,ans;
int st,ed;
bool check(int x){
	if(x==ed){ans=x;return 1;}
	if(x<0)return 0;
	if(x>=N)return 0;
	if(c[x])return 0;
	return 1;
}
int turn(int i,int op){
	switch(op){
		case 0:return i-1;
		case 1:return i+1;
		case 2:return 2*i;
	}
}
void bfs(){
	t=0;cur=0;ans=0;
	s[t++]=st;
	for(;;)
	{
		st=s[cur++];
		if(!check(st))continue;
		if(ans)break;
		for(int i=0;i<3;i++){
			int tem=s[t++]=turn(st,i);
			if(!d[tem])d[tem]=d[st]+1;
		}
//		for(int i=0;i<20;i++){
//			cout<<" i "<<i<<" d[i] "<<d[i]<<" c[i] "<<c[i]<<" s[i] "<<s[i]<<endl;}

		c[st]=1;
	}
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(scanf("%d%d", &st,&ed)!=EOF){
		memset (c,0,sizeof(c));
		memset (s,0,sizeof(s));
		memset (d,0,sizeof(d));
		bfs();
		printf("%d\n", d[ans]);
	}
	

	
	//insert code
	return 0;
}
//eoj641.cc

//AC

