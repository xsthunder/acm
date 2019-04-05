#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
const int N = 1e5 + 100;
struct Node {
	int c,x,y;
}ps[N];
int n,k;
bool operator < ( Node & a,Node & b){
	return a.x%k > b.x%k;
}
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
char tmp[5];
int good[N];
void inp(){
	scanf("%d%d",&n,&k);
	for(int i =0 ;i<n;i++)
		scanf("%d%d%s",&ps[i].x, &ps[i].y, tmp)
				,ps[i].c = (tmp[0] == 'W'?0:1);
	sort(ps,ps+n);
	int ans = 0;
	for(int y = 0;y < k;y++){
		int p = 0, cntgood = 0;
		for(int i =0 ;i<n ;i++){
			good[i] = ( ps[i].c 
									== 
										(ps[i].x / k + (ps[i].y+y)/k )%2);
			cntgood+= good[i];
		}
		for(int x = 0;x < k;x++){
			while( p<n && ps[p].x%k + x >= k){
				cntgood -= good[p];
				good[p] = !good[p];
				cntgood += good[p];
				p++;
			}
			ans = max( ans,
									max( cntgood, n - cntgood )
										);
		}
	}
	printf("%d\n", ans);
}
//D.cc by xsthunder at Sun Jan 21 20:30:49 2018

