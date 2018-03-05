#include<cstdio>
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
	while(1)inp();
	return 0;
}
const int N = 100000 + 100;
int sta[N];
void inp(){
	int n;scanf("%d",&n);if(!n)exit(0);
	MS(sta,0);
	for(int i =0;i<n;i++){
		int a,b;scanf("%d%d",&a,&b);
		sta[a]++;sta[b+1]--;
	}
	for(int i =1;i<N;i++){
		sta[i] += sta[i-1];
	}
	for(int i =1 ;i<=n;i++){
		if(i!=1)putchar(' ');
		printf("%d",sta[i]);
	}
	putchar('\n');
}
//hdu1556.cc by xsthunder at Thu Nov  2 09:04:56 2017

//AC at Thu Nov  2 09:09:44 2017
 
