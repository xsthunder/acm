#include<cstdio>
#include<algorithm>
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
	while(1)inp();
	return 0;
}
typedef int db;
const int N = 200;
struct OOO{
	db p,m;
}p[N];
bool operator < ( OOO a ,OOO b){
	return a.p>b.p;
}
const db eps = 1e-9;
int dcmp(db x){
	if((x)==0)return 0;
	return x < 0?-1:1;
}
void inp(){
	int n;db m,ans = 0;
	if(2!=scanf("%d%d", &m,&n))exit(0);
	for(int i =0;i<n;i++)scanf("%d%d",&p[i].p,&p[i].m);
	sort(p,p+n);
	for(int i=0;i<n;i++){
		if(dcmp(m) == 0){
			printf("%d\n",ans);
			return;
		}
		if(dcmp(m-p[i].m)>=0){
			m -= p[i].m;
			ans += p[i].p * p[i].m;
		}
		else {
			ans += p[i].p * m;
			m = 0;
		}
	}
	printf("%d\n",ans);
	return;
}
//tmp.cc by xsthunder at Sun Nov 26 09:53:56 2017

