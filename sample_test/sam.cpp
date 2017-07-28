
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
#include <time.h>
using namespace std;
#define LL __int64
#define pi acos(-1.0)
//#pragma comment(linker, "/STACK:1024000000")
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
const int MAXN=200000+10;
int n, k, head[MAXN], cnt, root, min1, ans;
int F[MAXN];//F[i]表示在该子树之前所遍历的所有子树的路径上不超过i个黑点的路径的最长长度
int G[MAXN];//表示严格有i个黑点的最长路径
int siz[MAXN], color[MAXN], vis[MAXN], num[MAXN];
struct node
{
        int u, v, w, next;
}edge[MAXN<<1];
struct N
{
        int v, num, w;
}T[MAXN];
bool cmp(N x, N y)
{
        return x.num<y.num;
}
void add(int u, int v, int w)
{
        edge[cnt].v=v;
        edge[cnt].w=w;
        edge[cnt].next=head[u];
        head[u]=cnt++;
}
void init()
{
        memset(head,-1,sizeof(head));
        memset(color,0,sizeof(color));
        memset(vis,0,sizeof(vis));
        cnt=0;
}
void getroot(int u, int fa, int s)
{
        int i, max1=-1;
        for(i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getroot(v,u,s);
                max1=max(max1,siz[v]);
        }
        max1=max(max1,s-siz[u]);
        if(min1>max1){
                min1=max1;
                root=u;
        }
}
void getsize(int u, int fa)
{
        siz[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getsize(v,u);
                siz[u]+=siz[v];
        }
}
void getnum(int u, int fa)
{
        num[u]=color[u];
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getnum(v,u);
                num[u]=max(num[u],num[v]+color[u]);
        }
}
void getG(int u, int fa, int dep, int val)
{
        G[dep]=max(G[dep],val);
        for(int i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(v==fa||vis[v]) continue ;
                getG(v,u,dep+color[v],val+edge[i].w);
        }
}
void work(int u)
{
        vis[u]=1;
        int i, j;
        int tot=0;
        for(i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(vis[v]) continue ;
                getnum(v,-1);
                T[tot].v=v;
                T[tot].num=num[v];
                T[tot].w=edge[i].w;
                tot++;
        }
        sort(T,T+tot,cmp);
        int lim=k-color[u];
        for(i=0;i<=T[tot-1].num;i++) F[i]=-INF;
        for(i=0;i<tot;i++){
                for(j=0;j<=T[i].num;j++) G[j]=-INF;
                getG(T[i].v,u,color[T[i].v],T[i].w);
                if(i){
                        for(j=0;j<=T[i].num&&j<=lim;j++){
                                int tmp=min(lim-j,T[i-1].num);
                                if(F[tmp]==-INF) continue ;
                                ans=max(ans,F[tmp]+G[j]);
                        }
                }
                for(j=0;j<=T[i].num&&j<=lim;j++){
                        F[j]=max(F[j],G[j]);
                        if(j) F[j]=max(F[j],F[j-1]);
                        ans=max(ans,F[j]);
                }
        }
        for(i=head[u];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(vis[v]) continue ;
                getsize(v,-1);
                min1=INF;
                getroot(v,-1,siz[v]);
                work(root);
        }
}
int main()
{
        int m, i, u, v, w, x;
        while(scanf("%d%d%d",&n,&k,&m)!=EOF){
                init();
                for(i=0;i<m;i++){
                        scanf("%d",&x);
                        color[x]=1;
                }
                for(i=1;i<n;i++){
                        scanf("%d%d%d",&u,&v,&w);
                        add(u,v,w);
                        add(v,u,w);
                }
                ans=0;
                getsize(1,-1);
                min1=INF;
                getroot(1,-1,n);
                work(root);
                printf("%d\n",ans);
        }
        return 0;
}
