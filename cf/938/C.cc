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
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int mxP = 1e5;
int prime[mxP], cntP=0;
int isP[mxP];
void init(){
	for(int i = 2;i<mxP;i++){
		if( !isP[i] )prime[cntP++] = i;
		for(int j = i + i;j<mxP;j += i){
			isP[j] = 1;
		}
	}
}
struct ANSF{
	int cnt,P;
}ansF[40];
void getF( int x,int &cntF){
	cntF = 0;
	for(int i = 0;i<cntP && prime[i] * prime[i] <= x;i++){
		if(x%prime[i] == 0){
			ansF[ cntF ] = ANSF{0,prime[i]};
			while( x % prime[i] == 0){
				ansF[ cntF ].cnt ++;
				x /= prime[i];
			}
			cntF ++;
		}
	}
	if(x > 1)ansF[cntF++] = ANSF{1,x};
}
int now[40];
bool nxt(int cntF,int &y){
	y = 1;
	for(int i = 0;i<cntF;i++){
		for(int j = 0;j<now[i];j++){
			y *= ansF[i].P;
		}
		if( ansF[i].cnt != now[i] ){
			now[i] ++;
			y *= ansF[i].P;
			return 1;
		}
	}
	return 0;
}
void inp(){
	init();
	int T;scanf("%d",&T);
	int cntF,x,y,X,de;
	int n,m;
	while(T--){
		scanf("%d",&X);
		if(!X){
			puts("1 1");
			continue;
		}
		getF(X, cntF);
		MS(now,0);y = 1;
		n = 0,m = 0;
		do{
			x = X / y;
			if( y > x )break;
			if( (x + y)&1 )continue;
			n = (x + y)/2;
			de = abs(x - y);
			if( de & 1)continue;
			de /= 2;
			if( n%de != 0)continue;
			m = n/de;
		}while(nxt(cntF,y) && m > 0);
		if( m > 0)printf("%d %d\n",n,m);
		else puts("-1");
	}
}
//C.cc by xsthunder at Sat Feb 17 00:15:02 2018

