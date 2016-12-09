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
const int N=5e3+10;
int a[N];
void init(){
	for(int i=1;i<=N;i++)
	{
		a[i]=i;
	}

}
int Find(int x){
	if(a[x]==x)return x;
	int tmp=Find(a[x]);
	return tmp;
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);{
		init();
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			int xfa=Find(x);
			int yfa=Find(y);
			a[yfa]=xfa;
			a[y]=xfa;
		}
		while(p--){
			int x,y;
			scanf("%d%d",&x,&y);
			int xfa=Find(x);
			int yfa=Find(y);
			printf("%s\n",xfa==yfa?"Yes":"No");
		}
//		for(int i=1;i<=n;i++){
//		cout<<endl;
	}



	
	//insert code
	return 0;
}
