#include<cstdio>
const int TEST=0;
#define IF if(TEST)
#include<vector>
#include<queue>
#include<cstdlib>
#include<iostream>
typedef unsigned int U;
using namespace std;
struct Node{
	Node *l,*r;
	int v;
};
typedef Node *T;
Node * cn(int v){
	Node * tmp = (Node*)malloc(sizeof(Node));
	tmp->l=tmp->r=NULL;
	tmp->v=v;
	return tmp;
}
void init();
void que(int x);
T t;
int main(){
	int T,q,x;
	scanf("%d",&T);
	while(T--){
		t=cn(0);
		init();
		scanf("%d",&q);
		for(int i =0  ; i<q;i++){
			scanf("%d",&x);
			que(x);
		}
	}
}
void que(int x){
	T tmp = t->l;
	while(1){
		IF if(!tmp)exit(1);
		IF printf("tmp: %d x:%d\n",tmp->v,x);
		if(tmp->v>x){
			printf("E");
			tmp=tmp->r;
		}
		if(tmp->v<x){
			printf("W");
			tmp=tmp->l;
		}
		if(tmp->v==x){
			printf("\n");
			return ;
		}
	}
}
void insert(T t,int x){
	while(1){
		if(x<t->v){
			if(!t->r){
				t->r=cn(x);
				return ;
			}
			else t=t->r;
		}
		else {
			if(!t->l){
				t->l=cn(x);
				return ;
			}
			else t=t->l;
		}
	}
}
void init(){
	int n;
	scanf("%d", &n);
	int x;
	for(int i =0 ;i<n;i++){
		scanf("%d",&x);
		insert(t,x);
	}
	IF {queue<T> q;
		q.push(t);
		while(!q.empty()){
			T tmp = q.front();
			q.pop();
	//		cout<<(tmp->v);
			if(tmp->l)q.push(tmp->l);
			if(tmp->r)q.push(tmp->r);
			free(tmp);
		}
//		cout<<endl;
	}
}
//AC at Sun Mar 19 20:16:34 2017
 
