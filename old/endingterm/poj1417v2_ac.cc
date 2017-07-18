#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<cassert>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("poj1417v2.in","r",stdin);
	while(1);
#endif
	try{
		while(1)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 6e2+100;
int dp[N][N];
int col0[N];
int choi[N][N];
int vp[N][3];
int mp[N];
int w[N];
int p[N];
int n,p1,p2;
int find(int a){
	if(p[a]<0)return a;
	int ans = find(p[a]);
	w[a] = !(w[a]^w[p[a]]);
	p[a] = ans;
	return ans;
}
void uni(int a,int b,int fa,int fb,int c){
	if(p[fa]>p[fb]){
		swap(fa,fb);
		swap(a,b);
	}
	p[fa]+=p[fb];
	p[fb] = fa;
	w[fb] = (w[a] + w[b] + c)%2;
}
int vpsize;
void initdp(){
	MS(col0);
	MS(vp);
	vpsize = 0;
	for(int i = 1;i<= p1+p2;i++){
		find(i);
		if(p[i]>0&&w[i]==0)col0[p[i]]++;
	}
	for(int i = 1;i<= p1 + p2;i++){
		if(p[i]<0){
			vpsize++;
			vp[vpsize][2] = i;
			vp[vpsize][0] = col0[i];
			vp[vpsize][1] = -p[i] - col0[i];
		}
	}
}
void getdp(){
	MS(dp);
	dp[0][0] = 1;
	memset(choi,-1,sizeof(choi));
	for(int i = 1;i<= vpsize;i++){
		for(int c = 0;c < 2;c++){
			int val = vp[i][c];
			for(int j = 0;j <= p1; j++){
				if(dp[i-1][j]>0){
					dp[i][j+val] += dp[i-1][j];
					choi[i][j+val] = c;
				}
			}
		}
	}
}
bool initoutp(){
	if(dp[vpsize][p1]!=1)return 0;
	MS( mp);
	int tmp = p1;
	for(int i = vpsize;i>= 1;i--){
		int p = vp[i][2];
		int c;
		mp[p] = c = choi[i][tmp];
		tmp -= vp[i][c];
	}
	assert(tmp==0);
	return 1;
}
void outp(){
	for(int i = 1;i<= p1+p2;i++){
		int val = 0;
		int ip = p[i]<0?i:p[i];
		if(mp[ip]==w[i])val = i;
		if(val)printf("%d\n",val);
	}
}
void inp(){
	scanf("%d%d%d", &n,&p1,&p2);
	if(!n&&!p1&&!p2)exit(0);
	memset(p,-1,sizeof(p));
	fill(w,w+N,1);
	while(n--){
		int a,b,c;
		char s[10];
		scanf("%d%d%s",&a,&b,s);
		c = s[0]=='y'?1:0;
		int fa = find(a);
		int fb = find(b);
		if(fa == fb)continue;
		uni(a,b,fa,fb,c);
	}
	initdp();
	getdp();
	if(!initoutp()){
		printf("no\n");
		return;
	}
	outp();
	printf("end\n");
}
//poj1417v2.cc by xsthunder at Tue Jul 18 10:01:03 2017

//AC at Tue Jul 18 11:08:16 2017
 
