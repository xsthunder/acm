#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
void inp(){
	int n,k,a,sum;
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a);
		sum+=a;
		if(sum>=8){
			sum-=8;
			k-=8;
		}
		else {
			k-=sum;
			sum=0;
		}
		if(k<=0){
			printf("%d\n",i);
			return ;
		}
	}
	puts("-1");
}
//cf839a.cc by xsthunder at Mon Aug 14 08:39:38 2017

//AC at Mon Aug 14 08:47:56 2017
 
