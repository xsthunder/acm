#include<cstdio>
#include<set>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf831c.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
int sum[3333];
int K[3333];
set<int> se;
void inp(){
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	for(i=1;i<=k;i++){
		scanf("%d",&K[i]);
	}
	sort(sum+1,sum+n+1),sort(K+1,K+k+1);
	int s,j,subi;
	for(i=1;i<=n;i++){
		s=K[1]-sum[i];
		for(j=2,subi=i+1;j<=k&&subi<=n;){//i也要跳一个单位
			if(s+sum[subi]==K[j])j++;
			else subi++;
		}
		if(j==k+1)
			se.insert(s);
	}
	printf("%u\n",(int)se.size());
}
//cf831c.cc by xsthunder at Sun Aug  6 08:59:50 2017

//AC at Sun Aug  6 09:21:43 2017
 
