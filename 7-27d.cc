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
int p[N];
int d[N];
void is_prime(){
	for(int i=4;i<=5000;i++){ 	
		for(int j=2;j<i;j++){
			if(p[j])if(i%j==0){p[i]=0;break;}
		}
		if(p[i]==-1)p[i]=1;
	}
}
int solve(int x){
	if(d[x])return d[x];
	//else if(p[x])return d[x]=(x==1?1:2);
	else {
		int sum=0;
		for(int i=1;i<=x;i++){
			if(x%i==0){sum++;
			//if(x==210){cout<<x<<' '<<i<<' ';}}
			}
		}
		return d[x]=sum;
	}
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	memset (p,-1,sizeof(p));
	memset (d,0,sizeof(d));
	int T;
	p[1]=p[2]=p[3]=1;
	scanf("%d",&T);
	//is_prime();
	while(T--){
		int a,b;
		scanf("%d%d", &a,&b);
		int best=0;
		int besti=0;
		for(int i=a;i<=b;i++){
			if(solve(i)>best){
				best=solve(i);
				besti=i;
			}
		}
		printf("%d\n", besti);
	}
	//for(int i=1;i<=50;i++){
	//	printf("%d %d %d\n",i,p[i],d[i]);
	//}
	//insert code
	return 0;
}
//7-27d.cc

//AC

