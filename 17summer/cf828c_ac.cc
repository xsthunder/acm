#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf828c.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
#ifdef XS
const int N = 100;
#else
const int N = 3e6+100;
#endif
char s[N];
char t[N];
bool T[N*4];
#define lson(z) (z<<1)
#define rson(z) ((z<<1)+1)
#define mid int m=(L+R)>>1
#define pl L,m
#define pr m+1,R
void que(char *p,int l,int r,int rt,int L,int R){
	if(T[rt])return;
	if(r<L||R<l)return;
	mid;
	if(L==R){
		s[L]=*p;
		T[rt]=1;
		return;
	}
	if(r<=m){
		que(p,l,r,lson(rt),pl);
	}
	else if(l>=m+1){
		que(p,l,r,rson(rt),pr);
	}
	else {
		que(p,l,m,lson(rt),pl);
		que(p+m-l+1,m+1,r,rson(rt),pr);
	}
	T[rt]=T[lson(rt)]&&T[rson(rt)];
}
void inp(){
	int n;scanf("%d",&n);
	int k,i,j,x,len,ma=-1;
	for(i=0;i<n;i++){
		scanf("%s",t);
		scanf("%d",&k);
		len = strlen(t);
		for(j=0;j<k;j++){
			scanf("%d",&x);
			que(t,x,x+len-1,1,1,N);
			ma=max(x+len-1,ma);
		}
	}
	for(i=1;i<=ma;i++){
		if(!s[i])putchar('a');
		else putchar(s[i]);
	}
	putchar('\n');
}
//cf828c.cc by xsthunder at Wed Aug  9 09:19:51 2017

//AC at Wed Aug  9 18:07:14 2017
 
