#include<cstdio>
#include<queue>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("suodian.in","r",stdin);
#endif
	int n;scanf("%d",&n);for(int i=0;i<n;i++)inp();
	return 0;
}
namespace DirectedGraph{
	static const int N = 10000+1000;
	static const int NE=100000+1000;
	int n;
	int ecnt=0,head[N];
	struct E{ int f,t,w,n;bool isqiao;void set(int f,int t,int w,int n){this->f=f,this->t=t,this->w=w,this->n=n,this->isqiao=0;}
	}es[NE];
	void initTree(){ ecnt=0; MS(head,-1),MS(es,0); }
	void ae(int f,int t,int w){ es[ecnt].set(f,t,w,head[f]),head[f]=ecnt,ecnt++; }
};
namespace TarjanDG{
	//depend vector min
	using namespace DirectedGraph;
	int time[N],low[N],Stack[N],top,clock;
	int taj;
	int Belong[N];
	bool Instack[N];
	vector<int >bcc[N];
	void tarjan(int u){
		time[u]=low[u]=++clock;
		Stack[top++]=u;
		Instack[u]=1;
		E e;
		for(int i =head[u];i!=-1;i=e.n){
			e=es[i];
			if(time[e.t]==-1){
				tarjan(e.t);
				low[u]=min(low[u],low[e.t]);
				if(time[u]<low[e.t]){ es[i].isqiao=1; }//不能绕过u
			}
			else if(Instack[e.t])low[u]=min(low[u],low[e.t]);
		}
		if(low[u]==time[u]){
			int now;
			taj++;bcc[taj].clear();
			do{
				now=Stack[--top];
				Instack[now]=0;
				Belong[now]=taj;
				bcc[taj].push_back(now);
			}while(now!=u);
		}
	}
	void TarjanDGinit(){
		MS(time,-1),MS(Instack,0);
		top=clock=taj=0;
		for(int i =1;i<=n;i++)if(time[i]==-1)tarjan(i);
	}
}
namespace Suodian{
	using namespace TarjanDG;
	//depend vector
	vector<int> G[N];
	int Indegree[N];
	void suodian(){
		MS(Indegree,0);
		TarjanDGinit();
		for(int i =1;i<=taj;i++)G[i].clear();
		for(int i=0;i<ecnt;i++){
			int u=Belong[es[i].f],v=Belong[es[i].t];
			if(u!=v)G[u].push_back(v),Indegree[v]++;
		}
	}
}
namespace Topo{//判定是否单连通
	//缩点拓扑排序中始终只出现一个入度为0的点,缩点后已经是DAG
	//depend queue
	using namespace Suodian;
	bool topo(){
		suodian();
		queue<int> q;
		for(int i=1;i<=taj;i++){
			if(!Indegree[i])q.push(i);
		}
		int cnt=0;
		while(!q.empty()){
			if(q.size()>1)return 0;
			int u=q.front(); q.pop();cnt++;
			for(int i =0;(U)i<G[u].size();i++){
				if(--Indegree[G[u][i]]==0)q.push(G[u][i]);
			}
		}
		return cnt==taj;
	}
}
void inp(){
	using namespace Topo;
	int m;scanf("%d%d",&n,&m);if(!n&&!m)exit(0);
	initTree();
	int a,b;
	for(int i =0;i<m;i++){
		scanf("%d%d",&a,&b);ae(a,b,0);
	}
	if(topo())puts("I love you my love and our love save us!");
	else puts("Light my fire!");
}
//suodian.cc by xsthunder at Wed Aug 23 13:16:10 2017

