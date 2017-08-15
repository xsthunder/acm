#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<bitset>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int  N = 5e4+10;
bitset<N> a;
bitset<N> b,bb;
bitset<N> ans;
void inp(){
	int n,m,q;scanf("%d%d%d",&n,&m,&q);
	int i,x;
	a.reset(),b.reset(),bb.reset(),ans.reset();
	int maxK = 0,maxA=0;
	for(i =0 ;i<n;i++){ scanf("%d",&x);a.set(x);if(x>maxA)maxA=x; }
	for(i =0 ;i<m;i++){ scanf("%d",&x);b.set(x);if(x>maxK)maxK=x; }
	int j;
	for(i=maxK;i>=0;--i){
		ans[i] = (bb&(a>>i)).count()&1;
		if(b[i]){
			for(j=0;j<=maxA;j+=i){
				bb.flip(j);
			}
		}
	}
	for(i=0;i<q;++i){
		scanf("%d",&x);
		printf("%d\n",ans[x]?1:0);
	}
}
//hdu6085.cc by xsthunder at Wed Aug  9 20:05:41 2017

//AC at Wed Aug  9 20:21:52 2017
 
