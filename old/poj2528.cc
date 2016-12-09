#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e4+100;
vector<int > coord;
struct node{
	int kind;
	int r;
	int l;
};
node nodes[2*4*N];
int l[N],r[N];
int getid(int val){
	return lower_bound(coord.begin(),coord.end(),val)-coord.begin()+1;
}
void build( int l,int r,int root){
	nodes[root].l=l;
	nodes[root].r=r;
	nodes[root].kind=0;
	if(l==r){
		return ;
	}
	else {
		int mid=(l+r)/2;
		build(l,mid,root*2);
		build(mid+1,r,root*2+1);
	}
}
void update(int l,int r,int root,int cover){
	//printf("in updat %d %d %d %d \n",l,r,root,cover);
	int lc=nodes[root].l;
	int rc=nodes[root].r;
	if(l==lc&&r==rc){
		nodes[root].kind=cover;
		//printf("set node[%d].kind=%d\n",root,cover);
		return ;
	}
	else {
		int left=root*2;
		int right=root*2+1;
		int mid=(lc+rc)/2;
		int kind=nodes[root].kind;
		if((kind!=0)&&kind!=cover){
			nodes[root].kind=0;
			nodes[left].kind=kind;
			nodes[right].kind=kind;
			//printf("set node[%d].kind=%d\n",left,kind);
			//printf("set node[%d].kind=%d\n",right,kind);
		}
		if(r<=mid){
			update(l,r,left,cover);
		}
		else if(l>=mid+1){
			update(l,r,right,cover);
		}
		else {
			update(l,mid,left,cover);
			update(mid+1,r,right,cover);
		}
	}
}
int ans;
bool mark[N];
int n;
void cal(int id){
	int left=id*2;
	int right=id*2+1;
	int kind =nodes[id].kind;
	if(id>4*n)return ;
	if(kind){
		if(!mark[kind]){
			mark[kind]=1;
			ans++;
			//printf("in cal id:%d kind:%d\n", id,kind);
		}
	}
	else if(kind==0){
		cal(left);
		cal(right);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ans=0;
		coord.clear();
		memset(nodes,0,sizeof(nodes));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(mark,0,sizeof(mark));
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			scanf("%d%d", &l[i],&r[i]);
			coord.push_back(l[i]);
			coord.push_back(r[i]);
		}
		sort(coord.begin(),coord.end());
		coord.erase(unique(coord.begin(),coord.end()),coord.end());
		build(1,coord.size(),1);
		for(int i=1;i<=n;i++){
			//printf("val:id %d:%d %d:%d\n",l[i],r[i],getid(l[i]),getid(r[i]));
			update(getid(l[i]),getid(r[i]),1,i);
		}
		ans=0;
		cal(1);
		printf("%d\n",ans);
	}
}
