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
const int N=1e3;
int G[N][N];
int vis[N][N];
int n;
deque<int > ans;
void euler(int u){
	for(int v=0;v<n;v++)if(G[u][v]&&!vis[u][v]){
		vis[u][v]=vis[v][u]=1;
		euler(v);
		//printf("%d %d\n", u,v);
		ans.push_front(u);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++);
//				printf("G[%d][%d]:%d vis[%d][%d]:%d vis[%d][%d]:%d\n" ,i,j,G[i][j],i,j,vis[i][j],j,i,vis[j][i]);
	}
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int t;
	while( scanf("%d%d ", &n,&t)!=EOF){
		memset (vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		while(t--){
			ans.clear();
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			G[x][y]=1;
			G[y][x]=1;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++);
	//				printf("G[%d][%d]:%d vis[%d][%d]:%d vis[%d][%d]:%d\n" ,i,j,G[i][j],i,j,vis[i][j],j,i,vis[j][i]);
			//cout<<"---------------------------\n";
		}

		int e;
		scanf("%d", &e);
		euler(e-1);
		for(int x:ans)cout<<x<<" ";
		cout<<endl;
	}

		

	
	//insert code
	return 0;
}
//euler.cc

