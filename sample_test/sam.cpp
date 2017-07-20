

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;
#define   MAX           500005
#define   MAXN          6005
#define   maxnode       15
#define   sigma_size    30
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   lrt           rt<<1
#define   rrt           rt<<1|1
#define   middle        int m=(r+l)>>1
#define   LL            long long
#define   ull           unsigned long long
#define   mem(x,v)      memset(x,v,sizeof(x))
#define   lowbit(x)     (x&-x)
#define   pii           pair<int,int>
#define   bits(a)       __builtin_popcount(a)
#define   mk            make_pair
#define   limit         10000

//const int    prime = 999983;
const int    INF   = 0x3f3f3f3f;
const LL     INFF  = 0x3f3f;
const double pi    = acos(-1.0);
//const double inf   = 1e18;
const double eps   = 1e-8;
const LL    mod    = 1e9+7;
const ull    mx    = 133333331;

/*****************************************************/
inline void RI(int &x) {
      char c;
      while((c=getchar())<'0' || c>'9');
      x=c-'0';
      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
 }
/*****************************************************/

struct Edge{
    int v,next;
}edge[MAX*2];
int head[MAX];
int tot;
int p1[MAX];
int p2[MAX];
int ti;
int sum[MAX<<2];

void init(){
    mem(head,-1);
    tot=0;ti=0;
}

void add_edge(int a,int b){
    edge[tot]=(Edge){b,head[a]};
    head[a]=tot++;
}

void dfs(int u,int fa){
    p1[u]=++ti;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dfs(v,u);
    }
    p2[u]=ti;
}

void pushup(int rt){
    sum[rt]=sum[lrt]+sum[rrt];
}

void build(int l,int r,int rt){
    if(l==r){
        sum[rt]=1;
        return;
    }
    middle;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int l,int r,int rt,int pos){
    if(l==r){
        sum[rt]=sum[rt]^1;
        return;
    }
    middle;
    if(pos<=m) update(lson,pos);
    else update(rson,pos);
    pushup(rt);
}

int query(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R) return sum[rt];
    middle;
    int ret=0;
    if(L<=m) ret+=query(lson,L,R);
    if(R>m) ret+=query(rson,L,R);
    return ret;
}

int main(){
    int n;
    cin>>n;
    init();
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add_edge(a,b);
        add_edge(b,a);
    }
    dfs(1,-1);
    build(1,n,1);
    int m;
    scanf("%d",&m);
    while(m--){
        char op;
        int a;
        getchar();
        scanf("%c%d",&op,&a);
        if(op=='Q') printf("%d\n",query(1,n,1,p1[a],p2[a]));
        else update(1,n,1,p1[a]);
    }
    return 0;
}
