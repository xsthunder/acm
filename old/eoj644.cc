#include<iostream>
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
const int N=7e4+10;
struct Node{
	int L,R,nex,val;
	Node(){
		this->L=this->R=this->nex=this->val=0;
	}
};
typedef struct Node Node;
Node a[N];
int n,m;
int t,op;
void init(){
	a[1].L=1;
	a[1].R=n;
	t=2;
}
int find(int left){
	Node &x=a[i];
	if(x.L>=left)return i;
	else return find(x.nex);
}
int sum(x,y){
	Node i= a[find(x)];
	if(x==y)return i.val;
	if(i.R>=y)return i.val*(y-x+1);
	else return i.val*(i.R-x+1)+sum(i.R+1,y);
}


int main()
{
#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int x,y,z;
	while( scanf("%d%d", &n,&m)&&n){
		init();
		while(m--){
			scanf("%d%d%d%d", &op,&x,&y,&z);
			for(;;)
			{
				if(op==4){
					printf("%d\n",sum(x,y));
					break;
				}
				Node &node=a[find(x)];	
				if(node.R>y){
					if(node.L==x){
						Node &nnode=a[t++];
						nnode=node.nex;
						node.nex=t-1;
						nnode.L=
						
					}
					else {

					}

				}

			}

		}
	}


	
	//insert code
	return 0;
}
//eoj644.cc

