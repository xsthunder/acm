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
	//freopen(".in","r",stdin);
#endif
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 100;
char s1[N],s2[N];
int c1,c2;
int de(char x){
	if(x == 'v')return 0;
	else if(x=='<')return 1;
	else if(x=='^')return 2;
	else return 3;
}
void inp(){
	scanf("%s%s",s1,s2);
	c1=de(s1[0]),c2=de(s2[0]);
	int n;scanf("%d",&n);n%=4;
	int t = (c2 - c1 +4)%4;
	if(t<0)t = -t;
	if(t == 0||t == 2){
		printf("undefined");
	}
	else if(t==n)printf("cw");
	else printf("ccw");
	printf("\n");
}
//cf834a.cc by xsthunder at Fri Aug  4 08:57:02 2017

//AC at Fri Aug  4 09:04:39 2017
 
