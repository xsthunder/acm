#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 2e5 + 100;
const ll MAX = 1e18;
#define iii i++
ll A[N];
ll S[N];
int n;
inline ll cal( int i ){
    ll b = A[i];
    return b* ( 2 * ( i + 1 ) - n) - S[i] + S[n-1] - S[i];
}
void inp(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++)scanf("%lld", &A[i]), A[i]-=i+1;
    sort(A, A+n);
    S[0]=A[0]; for(int i =1 ;i<n;i++) S[i]=S[i-1]+A[i] ;
    ll ans = MAX;
    for(int i =0 ;i<n;iii){
        ans = min(ans, cal(i));
    }
    printf("%lld\n", ans);
}
//c.cc by xsthunder at Tue Jul 31 17:19:35 2018

//AC at Fri Aug  3 17:11:53 2018
 
