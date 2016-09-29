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
using namespace std;
const int inf=0x7fffffff;
const int N=1000+10;
struct box{int w,l;};box boxs[N];
int n;
int best;
void bfs(int i,int cnt,int cur_load,const int &max_load)
{
	if(cnt+n-i<=best)return;
	if(cnt!=1)cur_load+=boxs[i].w;
	if(cnt>best)best=cnt;
	cnt++;
	for(int j=i+1;j<=n;j++)
	{
		if(cur_load+boxs[j].w>max_load)return;
		bfs(j,cnt,cur_load,max_load);
	}
	return;

}


int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		best=0;
		memset(boxs,0,sizeof(boxs));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&boxs[i].w,&boxs[i].l);
#ifdef DEBUG
		//	printf("i:%d  %d %d\n",i,boxs[i].w,boxs[i].l);
#endif
		}
		for(int i=1;i<=n;i++)
			bfs(i,1,0,boxs[i].l);
		printf("%d\n",best);
	}

	
	//insert code
	return 0;
}
