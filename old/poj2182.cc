#include<cstdio>
#include<vector>
using namespace std;
const int N=8000+100;
struct node{
	int len;
};
node nodes[4*N];
void build(int lc,int rc,int root){
//	printf("in build %d %d %d \n",lc,rc,root);
	if(lc==rc){
		nodes[root].len=1;
		return ;
	}
	nodes[root].len=rc-lc+1;
	int mid =(lc+rc)/2;
	build(lc,mid,2*root);
	build(mid+1,rc,2*root+1);
}
int query(int lc,int rc,int len ,int root){
	//printf("in query %d %d %d %d:%d\n",lc,rc,len,root,nodes[root].len);
	if(lc==rc){
		nodes[root].len--;
		return lc;
	}
	else {
		nodes[root].len--;
		int left=2*root;
		int mid=(lc+rc)/2;
		if(len<=nodes[left].len){
			return query(lc,mid,len,left);
		}
		else {
			return query(mid+1,rc,len-nodes[left].len,2*root+1);
		}
	}
}
int small[N];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=2;i<=n;i++){
		scanf("%d", &small[i]);
	}
	small[1]=0;
	build(1,n,1);
	vector<int >vi;
	for(int i=n;i>=1;i--){
		vi.push_back(query(1,n,small[i]+1,1));
	//	printf("-----\n");
	}
	for(int i=vi.size()-1;i>=0;i--){
		printf("%d\n", vi[i]);
	}
	return 0;
}
