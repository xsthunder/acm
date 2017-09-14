#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("sam2.in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
const int N = 400;
char s[N],s2[N];
int len,len2;
int sum[N],sum2[N];
int ans;
void dfs(int d,int p,int r,int res){
	if(d==len2+1){
		ans=max(ans,res);
	}
	if(p>len)return;
	if(len-p+1<sum2[len2]-sum2[d-1])return;
	if(!r){
		res+=sum[len]-sum[p-1];
		ans=max(ans,res);
		return;
	}
	res+=sum[p+s2[d]-1]-sum[p-1];
	p+=s2[d];
	for(int i=0;i<=r;i++){
		dfs(d+1,p+i,r-i,res);
	}
}
void inp(){
	ans=0;
	if(scanf("%s",s+1)==EOF)exit(0);
	getchar();
	assert(s2+1==fgets(s2+1,N,stdin));
	len=strlen(s+1),len2=strlen(s2+1);len2--;
	for(int i=1;i<=len;i++)s[i]-='0';
	for(int i=1;i<=len2;i++)s2[i]-='a',s2[i]++;
	MS(sum,0);MS(sum2,0);
	for(int i=1;i<=len;i++)sum[i]=sum[i-1]+s[i];
	for(int i=1;i<=len2;i++)sum2[i]=sum2[i-1]+s2[i];
	assert(sum2[len2]<=len);
	int r = len;
	for(int i=1;i<=len2;i++)r-=s2[i];
	if(len2)for(int i=0;i<=r;i++){
		dfs(1,1+i,r-i,0);
	}
	printf("%d\n",ans);
}
//sam.cc by xsthunder at Thu Sep 14 21:36:46 2017

