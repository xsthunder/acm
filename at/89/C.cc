#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
const int N = 1e5+100;
struct Node {
	int t,x,y;
}ps[N];
bool operator <(Node &a,Node &b){ return a.t<b.t; }
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
void inp(){
	int n;scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d%d%d",&ps[i].t,&ps[i].x,&ps[i].y);
	}
	ps[n++] = Node{0,0,0};
	sort(ps,ps+n);
	for(int i = 1;i<n;i++){
		int A = ps[i].t - ps[i-1].t;
		int B = abs(ps[i].x - ps[i-1].x) 
					+ abs(ps[i].y - ps[i-1].y);
		if(A <= 0 || A < B || (A - B)%2){
			puts("No");
			return ;
		}
	}
	puts("Yes");
}
//C.cc by xsthunder at Sun Jan 21 20:03:12 2018

