#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	freopen("d.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 2e5 + 1000;
ll n, F[N], E[N];ll A[N], S[N] ;
ll calfa(int f,int e){
    return abs(  S[e] - S[f] - S[f] );
}
void calf(){
    int f=1, e= 2;
    for(;e<=n;e++){
        while( f + 1 < e && (calfa(f,e) > calfa( f+1, e))){
                f ++;
        }
        F[e]=f;
    }
}
ll calea(int f,int e){
    return abs( S[n] - S[e-1] - (S[e-1] - S[f-1]) );
}
void cale(){
    int f,e;
    f = n-1, e = n;
    for(;f>=1;f--){
        while( e - 1 > f && ( calea( f, e ) > calea( f, e - 1 ) )) {
            e --;
        }
        E[f]=e;
    }
}
typedef ll (*Func)(ll,ll);
ll max(ll a,ll b){
    if( a > b)return a;
    return b;
}
ll min(ll a,ll b){
    if( a < b)return a;
    return b;
}
ll dist(ll a,ll b){
    return abs(a - b);
}
ll calfc(int i,Func func){
    //i --;
    int best = F[i];
    return func( S[best] , S[i] - S[best]);
}
ll calec( int f,Func func){
    f ++;
    int e= E[f];
    return func( S[n] - S[e-1], S[e-1] - S[f-1]);
}
ll calmax( int i ){
    return max( calfc(i, max) ,calec(i,max) );
}
ll calmin( int i ){
    return min( calfc(i, min) ,calec(i,min) );
}
void pA(ll *a,const char *s){
    puts(s);
    for(int i = 0;i<=n;i++){
        printf("%2lld ",a==NULL?i:a[i]);
    }
    putchar('\n');
}
void inp(){
    scanf("%lld", &n);for(int i =1 ;i<=n;i++)scanf("%lld", &A[i]);
    S[0]=A[0]=0;
    for(int i=1;i<=n;i++)S[i]=S[i-1]+A[i];
    calf();
    cale();
#ifdef XS
    pA(NULL,"I");
    pA(A,"A");
    pA(S,"S");
    pA(F,"F");
    pA(E,"E");
#endif
    ll ans = 1e18;
    for(int i = 2;i<n-1;i++){
        ll cur =  calmax(i)-calmin(i) ;
        cur =  max(cur, calfc(i, dist) );
        cur =  max(cur, calec(i, dist) );
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);
}
//d.cc by xsthunder at Thu Aug  2 10:14:47 2018

/*
4
5
5
4
7
*/
//AC at Fri Aug  3 17:12:00 2018
 
