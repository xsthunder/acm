#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<cassert>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
namespace Treap{
	//depend rand() time()
	struct Node{
		Node *ch[2];//左右子树
		static Node *null;
		int r,v,w;//优先值（越大越优先），值
		int cmp(int x)const {
			if(x==v)return -1;
			return x<v?0:1;//左子树，右子树 
		}
		void maintain(){ if(this!=null)this->w=this->ch[0]->w+this->ch[1]->w+1; }
	};
	Node* Node::null=NULL;
	Node* null=NULL;
	// todo make newNode new Node
	Node* newNode(int x){Node *p=new Node();p->ch[0]=p->ch[1]=null,p->r=rand(),p->v=x,p->w=1; return p;}
	void init(){srand(time(0)); Node::null=null=newNode(-1);null->r=-1;null->ch[0]=null->ch[1]=null,null->w=0; }
	void rotate(Node *&o,int d){//d=0左旋，d=1右旋
		Node*k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;
		o->maintain(), k->maintain(),o=k;
	}
	void insert(Node *&o,int x){
		if(o==null){ o=newNode(x); }
		else {
			int d=o->v<x?1:0;//multi support
			insert(o->ch[d],x);o->maintain();
			if(o->ch[d]->r>o->r){ rotate(o,d^1); }
		}
	}
	void remove(Node *&o,int x){
		int d=o->cmp(x);
		Node *tmp=o;
		if(d==-1){
			if(o->ch[0]==null)o=o->ch[1],delete tmp;
			else if(o->ch[1]==null)o=o->ch[0],delete tmp;
			else {
				int d2=(o->ch[0]->r>o->ch[1]->r)?1:0;
				rotate(o,d2);remove(o->ch[d2],x);
			}
		}
		else remove(o->ch[d],x);
		o->maintain();
	}
	bool nfind(Node *o,int x){//maybe tail recursion , no reference
		int d;
		while(o!=null){
			d=o->cmp(x);
			if(d==-1)return 1;
			else o=o->ch[d];
		}
		return 0;
	}
	void ptree(Node *o,int x=0){
		if(o==null)return ;
		int f=4;
		if(o->ch[1]!=null)ptree(o->ch[1],x+f);
		printf("%*s w:%d v:%d r:%d\n",x,"",o->w,o->v,o->r);
		if(o->ch[0]!=null)ptree(o->ch[0],x+f);
	}
}
using namespace Treap;
int main(){
#ifdef XS
	freopen("treap.in","r",stdin);
#endif
	init();
	while(1) inp();
	return 0;
}
const int N  = 20000+100;
const int NQ = 400000;
const int NE = 60000+100;
struct Que{
	char c; int x,y;
	void set(char c,int x,int y=0){ this->c=c,this->x=x,this->y=y; }
}qs[NQ];
int val[N],ecnt,laz[NE],qcnt;
char s[10];
P es[NE];
Node* treap[N];
int fa[N];
void mergeto(Node* &f,Node *&t){
	assert(t!=null);
	if(f==null)return;
	mergeto(f->ch[0],t); mergeto(f->ch[1],t);
	insert(t,f->v); delete f;f=null;
}
int que(Node*f,int k){
	if(f==null)return 0;
	if(k<0)return 0;
	if(k>=f->w)return 0;
	if(k==f->ch[0]->w)return f->v;
	else if(f->ch[0]->w>k)return que(f->ch[0],k);
	else return que(f->ch[1],k-f->ch[0]->w-1);
}
int find(int x){ return fa[x]<0?x:fa[x]=find(fa[x]); }
void uni(int x,int y){ 
	x=find(x),y=find(y); if(x==y)return;
	if(fa[x]>fa[y])swap(x,y);
	mergeto(treap[y],treap[x]);treap[y]=null;
	fa[x]+=fa[y]; fa[y]=x; 
}
int n,m;
void debug(){
	for(int i =1;i<=n;i++){
		if(treap[i]!=null){
			printf("treap[%d]vvv\n",i);
			ptree(treap[i]);
		}
		fflush(stdout);
	}
}
int TT=0;
void inp(){
	scanf("%d%d",&n,&m);
	if(!n&&!m)exit(0);MS(laz,0);MS(fa,-1);
	for(int i =1;i<=n;i++){ scanf("%d",&val[i]); }
	for(ecnt=1;ecnt<=m;ecnt++){ scanf("%d%d",&es[ecnt].first,&es[ecnt].second);}
	int x,y;char c;
	for(scanf("%s",s),qcnt=1,c=s[0];c!='E';scanf("%s",s),c=s[0],qcnt++){
		if(c=='D'){ scanf("%d",&x);laz[x]=1;y=es[x].second;x=es[x].first; }
		else if(c=='Q'){scanf("%d%d",&x,&y);}
		else { scanf("%d%d",&x,&y); swap(val[x],y); }
		qs[qcnt].set(c,x,y);
	}
	treap[0]=null;
	for(int i =1;i<=n;i++)treap[i]=newNode(val[i]);
	for(int i = 1;i<ecnt;i++){
		if(laz[i])continue; x=es[i].first,y=es[i].second; uni(x,y);
	}
#ifdef XS
	debug();
#endif
	ll ans=0,cnt=0;
	for(int i =qcnt-1;i>=1;i--){
		c=qs[i].c,x=qs[i].x,y=qs[i].y;
		if(c=='D'){ uni(x,y); }
		else if(c=='Q'){ int fx=find(x); ans+=que(treap[fx],-fa[fx]-y);cnt++; }
		else if(c=='C'){ int fx=find(x);remove(treap[fx],val[x]);insert(treap[fx],y);val[x]=y; }
#ifdef XS
		printf("%d %c %d %dvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ans:%lld\n",i,c,x,y,ans);
		debug();
//		if(i==6)break;
#endif
	}
#ifdef XS
	debug();
#endif
	printf("Case %d: %.6f\n",++TT,double(ans)/cnt);
}
//treap.cc by xsthunder at Fri Aug 25 16:21:28 2017

