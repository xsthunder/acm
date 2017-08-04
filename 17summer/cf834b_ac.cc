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
	freopen("cf834b.in","r",stdin);
#endif
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 1e6+100;
char s[N];
int t[N];
const int C = 30;
int b[C];
int e[C];
void inp(){
	int n,k,i;
	int c;
	scanf("%d%d%s",&n,&k,s);
#define de(z) ((z)-'A')
	MS(b,-1);
	for(i = 0;i<n;i++){
		c = de(s[i]);
		if(b[c]!=-1) e[c]=i;
		else b[c]=e[c]= i;
	}
	for(i = 0;i<C;i++){
		if(b[i]!=-1){
			t[b[i]] +=1;
			t[e[i]+1]-=1;
		}
	}
	int flag = 0;
	for(i = 1 ;i<N;i++){
		t[i]+=t[i-1];
		if(t[i]>k){
			flag = 1;
		}
	}
	char ans[][10]={
		"NO","YES"
	};
	printf("%s\n",ans[flag]);
}
//cf834b.cc by xsthunder at Fri Aug  4 09:08:01 2017

//AC at Fri Aug  4 09:22:07 2017
 
