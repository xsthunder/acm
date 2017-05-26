#include<algorithm>
#include<set>
#include<cstring>
#include<map>
#include<cstdio>
#include<queue>
using namespace std;
const int mN=100000+5000;//father
map<int ,int > vi[mN];
struct Node{
	int d;
	int f;
};
Node T[mN];
int cntT;
priority_queue<int > lens;
int Node[mN];
void inp();
void bui(int ,int,int );
void tbui();
const char ans[][10]={
	"No\n",
	"Yes\n"
};
int n;
int que(int ,int );
void dea();
int main(){
	int Tcase,q;
	int a,b;
	scanf("%d", &Tcase);
	while(Tcase--){
		memset(T,0,sizeof(T));
	//	cntT=0;
		inp();
//		printf("%d %d",Tcase, n);
		//tbui();
		scanf("%d",&q);
		while(q--){
			while(!lens.empty()){
				lens.pop();
			}
			scanf("%d%d", &a,&b);
			que(a,b);
			//printf("%d %d -> %d \n",a,b,que(a,b));
			dea();
		}
	}
//	printf("%d",Tcase);
}
void dea(){
	if(lens.size()<3){
		printf("%s",ans[0]);
		return ;
	}
	int a,b,c;
	while(lens.size()>=3){
		a=lens.top();lens.pop();
		b=lens.top();lens.pop();
		c=lens.top();lens.pop();
		if(b+c>a){
			printf("%s",ans[1]);
			return ;
		}
		lens.push(b),lens.push(c);
	}
	printf("%s",ans[0]);
}
int que(int a,int b){
	while(a!=b){
		if(T[a].d>T[b].d){
			lens.push(vi[a][T[a].f]);
			a=T[a].f;
		}
		else {
			lens.push(vi[b][T[b].f]);
			b=T[b].f;
		}
	}
	return a;
}
void tbui(){
	for(int i =1;i<=n;i++){
		printf("%d :%d %d \n ",i,T[i].d,T[i].f);
	}
}
void bui(int d,int f,int cur){
	T[cur].d=d;
	T[cur].f=f;
	for(auto it =vi[cur].begin();it!=vi[cur].end();it++){
		if(T[it->first].d)continue;
//		printf("%d:  %d\n",cur,it->first);
		bui(d+1,cur,it->first);
	}
}
int cntD[mN];
void inp(){
	memset(cntD,0,sizeof(cntD));
	int a,b,c;
	int cnt=1,root=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		vi[i].clear();
	}
	for(int i = 0; i< n-1;i++){
		scanf("%d%d%d",&a,&b,&c);
		cntD[a]++,cntD[b]++;
		vi[a][b]=c;
		vi[b][a]=c;
	}
	for(int i =1;i<=n;i++){
		if(cnt<cntD[i])root=i;
	}
	bui(1,root,root);
//	for(int i=1;i<=n;i++){
//		for(auto it =vi[i].begin();it!=vi[i].end();it++){
//			printf("%d :%d %d\n",i,it->first,it->second);
//		}
//	}
}
