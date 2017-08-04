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
	freopen("cf835b.in","r",stdin);
#endif
	inp();
	return 0;
}
const int N = 1e5 + 1000;
const int D = 9;
char s[N];
int cnt[20];
void inp(){
#define de(z) ((z)-'0')
	int len,k,sum,i,r;
	scanf("%d%s",&k,s);MS(cnt,0);
	len = strlen(s);
	sum = 0;
	for(i = 0;i<len;i++)cnt[de(s[i])]++;
	for(i = 0;i<=D;i++)sum+=i*cnt[i];
	r = k-sum;
	int ans =0,d;
	for(i = 0;r>0&&i<D;i++){
		d = (r+D-i-1)/(D-i);
		if(d>cnt[i]){
			r-=cnt[i]*(D-i);
			ans+=cnt[i];
		}
		else {
			r-=d*(D-i);
			ans+=d;
		}
	}
	printf("%d\n",ans);
}
//cf835b.cc by xsthunder at Thu Aug  3 08:35:06 2017

//AC at Thu Aug  3 09:16:52 2017
 
