#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
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
	freopen("poj1733.in","r",stdin);
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
#define mo(x) (x%=2)
const int N = 5e3+100;
int p[N*2];
int w[N*2];
int unq[N*2];
struct Q{
	int a,b;
	int c;
	Q(int a,int b,int c){
		this->a=a;this->b=b;this->c=c;
	}
	Q(){}
} q[N];
int find(int a){
	if(p[a]<0)return a;
	int pre = p[a];
	int ans = find(p[a]);
	w[a] += w[pre];
	mo(w[a]);
	p[a] = ans;
	return ans;
}
void inp(){
	int n,m; 
	MS(w);
	memset(p,-1,sizeof(p));
	if(!~scanf("%d", &n))exit(0);
	scanf("%d",&m);
	int size = 0;
	for(int i =0;i<m;i++){
		int a,b;
		char s[10];
		scanf("%d%d%s", &a,&b,s);
		a--;
		unq[size++]=a;
		unq[size++]=b;
		q[i]=Q(a,b,s[0]=='o'?1:0);
	}
	int * bit = unq;
	int * eit = unq+size;
	sort(bit,eit);
	eit = unique(bit,eit);
	for(int i = 0;i<m;i++){
		Q &qq = q[i];
		qq.a = lower_bound(bit,eit,qq.a)-bit;
		qq.b = lower_bound(bit,eit,qq.b)-bit;
	}
	int cnt = 0;
	for(;cnt<m;cnt++){
		Q qq = q[cnt];
		int fa = find(qq.a);
		int fb = find(qq.b);
		int a = qq.a;
		int b = qq.b;
		int c = qq.c;
#ifdef XS
		if(cnt==3)break;
#endif
		if(fa==fb){
			if(w[b]!=(w[a]+qq.c)%2){
				printf("%d\n",cnt);
				return;
			}
		}
		else {
			//uni
			if(fa>fb){
				swap(fa,fb);
				swap(a,b);
				mo(c);
			}
			p[fa]+=p[fb];
			w[fb] = ( w[a] + c + w[b])%2;
			p[fb] = fa;
		}
	}
#ifdef XS
	pA(unq,size);
	pA(p,size);
	pA(w,size);
#endif
	printf("%d\n", m);
}
//poj1733.cc by xsthunder at Sat Jul 15 16:11:16 2017

//AC at Sat Jul 15 19:50:41 2017
 
