#include<cstdio>
#include<map>
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
map<ll ,ll>mp;
void inp(){
	int n,x;scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		if(mp.count(x))mp[x]++;
		else mp[x]=1;
	}
	ll a[2],cnt=0;
	for(auto it=mp.rbegin();it!=mp.rend()&&cnt<2;++it){
		//printf("%lld %lld\n",it->first,it->second);
		if(it->second>=2&&cnt<2){
			a[cnt++]=it->first;
			it->second-=2;
		}
		if(it->second>=2&&cnt<2){
			a[cnt++]=it->first;
			it->second-=2;
		}
	}
	if(cnt<2)puts("0");
	else printf("%lld\n",a[0]*a[1]);
}
//at81c.cc by xsthunder at Sun Aug 20 20:01:41 2017

//AC at Sun Aug 20 20:19:29 2017
 
