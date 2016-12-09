#include<iostream>
#include<algorithm>
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
const int N =1e3 +10;
int n;
int a[N];
int d[N];
int p[N];
vector<int>r[N];
int solve(int x){
	if(d[x]>0)return d[x];
	else {
		int best =1;
		for(int i=x+1;i<=n;i++){
			if(a[x]>=a[i])continue;
			for(int i=1;i<=n;i++)printf("%3d",i);cout<<endl;
			for(int i=1;i<=n;i++)printf("%3d",d[i]);cout<<endl;
			int temp=solve(i)+1;
			if(best<temp){
				best=temp;
				p[x]=i;
			}
		}
		return d[x]=best;
	}
}
void print_ans(int x){
	cout<<a[x]<<" ";
	int temp=p[x];
	if(p[x]==-1)return ;
	else print_ans(temp);
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(scanf("%d",&n)!=EOF){
		memset(p,-1,sizeof(p));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			scanf("%d", a+i);
			r[i].clear();
		}
		int best =-1;
		int besti=-1;
		d[n]=1;
		for(int i=1;i<=n;i++){
			int temp=solve(i);
			if(best<temp){
				best=temp;
				besti=i;
			}
		}
		if(best==-1)cout<<"no";
		else{
			printf("%d %d\n",best,besti);
			print_ans(besti);
		}
	}
	//insert code
	return 0;
}
//poj2533.cc

//AC
//trys to output the route//succeeded
