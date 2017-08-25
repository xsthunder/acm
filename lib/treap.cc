#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("treap.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
namespace Treap{
	//depend rand() time()
	struct Node{
		Node *ch[2];//左右子树
		int r,v;//优先值（越大越优先），值
		int cmp(int x)const {
			if(x==v)return -1;
			return x<v?0:1;//左子树，右子树 
		}
	};
	Node* null=NULL;
	Node* newNode(int x){Node *p=new Node();p->ch[0]=p->ch[1]=null,p->r=rand(),p->v=x; return p;}
	void init(){srand(time(0)); null=newNode(-1);null->r=-1; }
	void rotate(Node *&o,int d){//d=0左旋，d=1右旋
		Node*k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;o=k;
	}
	void insert(Node *&o,int x){
		if(o==null){ o=newNode(x); }
		else {
			int d=o->cmp(x);
			insert(o->ch[d],x);if(o->ch[d]->r>o->r)rotate(o,d^1);
		}
	}
	void remove(Node *&o,int x){
		int d=o->cmp(x);
		if(d==-1){
			if(o->ch[0]==null)o=o->ch[1];
			else if(o->ch[1]==null)o=o->ch[0];
			else {
				int d2=(o->ch[0]->r>o->ch[1]->r)?1:0;
				rotate(o,d2);remove(o->ch[d2],x);
			}
		}
		else remove(o->ch[d],x);
	}
	bool find(Node *o,int x){//maybe tail recursion , no reference
		int d;
		while(o!=null){
			d=o->cmp(x);
			if(d==-1)return 1;
			else o=o->ch[d];
		}
		return 0;
	}
}
void inp(){
	using namespace Treap;
	int n,x;
	init();
	scanf("%d",&n);
	Node* treap=null;//never forget to init a pointer
	int icnt=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		int t=find(treap,x);
		if(!t)icnt++,insert(treap,x);
	}
	printf("in->%d\n",icnt);
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		printf("%d %d\n",x,find(treap,x));
	}
	scanf("%d",&n);
	int cnt=0;
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		int t=find(treap,x);
		if(t){
			cnt++;
			remove(treap,x);
		}
	}
	printf("out->%d\n",cnt);
}
//treap.cc by xsthunder at Fri Aug 25 16:21:28 2017

