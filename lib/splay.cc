#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
namespace Splay{
	struct Node{
		static Node* null;
		int s,v;bool filp;
		Node* ch[2];
		int cmp(int k)const{
			if(k==this->ch[0]->s+1)return -1;
			return this->ch[0]->s+1>k?0:1;
		}
		void mt(){//short for maintain
			this->s=this->ch[0]->s+this->ch[1]->s+1;
		}
		void push(){
			if(filp){
				filp=0;
				swap(ch[0],ch[1]);
				ch[0]->filp=!ch[0]->filp;
				ch[1]->filp=!ch[1]->filp;
			}
		}
		Node(int v){
			this->s=1,this->filp=0,this->ch[0]=this->ch[1]=this->null,this->v=v;
		}
	};
	Node* null=NULL; Node* Node::null=NULL;
	Node * init(int n){
		null = Node::null=new Node(-1); null->ch[0]=null->ch[1]=null;null->s=0,null->filp=0;
		Node* root=new Node(0);
		Node* tmp=null;
		for(int i =1;i<=n;i++){
			tmp=new Node(i);
			tmp->ch[0]=root;
			tmp->mt();
			root=tmp;
			tmp=null;
		}
		return root;
	}
	void rotate(Node *&o,int d){
		Node * k=o->ch[d^1];
		o->ch[d^1]=k->ch[d],k->ch[d]=o,o->mt(),k->mt(),o=k;
	}
	void splay(Node *&o ,int k){
		o->push();
		int d=o->cmp(k);
		if(d==1)k-=o->ch[0]->s+1;
		if(d!=-1){
			Node* &p = o->ch[d];
			p->push();
			int d2=p->cmp(k);
			if(d2==1)k-=p->ch[0]->s+1;
			if(d2!=-1){
				splay(p->ch[d2],k);
				rotate(p,d2^1);
			}
			rotate(o,d^1);
		}
	}
	Node *merge(Node*left,Node*right){//left !=null
		Node *o;
		splay(left,left->s);
		splay(right,1);
		left->ch[1]=right;
		left->mt();o=left;
		left=right=null;
		return o;
	}
	void split(Node*o,int k,Node*&left,Node*&right){
		splay(o,k);
		right=o->ch[1];
		o->ch[1]=null;
		o->mt();
		left=o;
		o=null;
	}
}
using namespace Splay;
void dfs(Node * root){
	if(root->filp)root->push();
	if(root->ch[0]!=null)dfs(root->ch[0]);
	if(root->v)printf("%d\n",root->v);
	if(root->ch[1]!=null)dfs(root->ch[1]);
}
void pt(Node *root,int w=0){
	int f=4;
	if(root->ch[1]!=null)pt(root->ch[1],w+f);
	printf("%*s v:%d,s:%d filp:%d\n",w,"",root->v,root->s,root->filp);
	if(root->ch[0]!=null)pt(root->ch[0],w+f);
}
void debug(Node *rt,string s=""){
#ifdef XS
	printf("%s-----vvvvvvvvv\n",s.c_str());
	pt(rt);
	fflush(stdout);
#endif
}
void de(Node *rt){
	pt(rt);
	fflush(stdout);
}
void inp(){
	int n,m;
	scanf("%d%d",&n,&m);
	Node *root=init(n),*left=NULL,*right=NULL,*mid=NULL;int a,b;
	debug(root,"root");

	for(int i =0;i<m;i++){
		scanf("%d%d",&a,&b);
		split(root,a,left,mid);root=NULL;
		split(mid,b-a+1,mid,right);
		debug(left,"left");
		debug(mid,"mid");
		debug(right,"right");
		mid->filp^=1;
		root=merge(left,right);left=right=NULL;
		root=merge(root,mid);mid=NULL;
		debug(root,"root");
	}
	dfs(root);
}
int main(){
#ifdef XS
	freopen("splay.in","r",stdin);
#endif
	inp();
	return 0;
}
//splay.cc by xsthunder at Sat Aug 26 20:47:31 2017

