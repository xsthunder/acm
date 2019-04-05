#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<algorithm>
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
const int N = 1e5 + 100;
P P1[N],P2[N];
#define A first
#define B second
bool getI( P &a, P &b, P &ans){
	int x, y;
	x = max(a.A, b.A);
	y = min(a.B, b.B);
	if( x < y ){
		ans.A = x,ans.B = y;
		return true;
	}
	return false;
}
void pP( P * arr, int n ){
	printf("vvv\n");
	for(int i =0;i<n;i++){
		printf("%d %d\n", arr[i].A, arr[i].B);
	}
	printf("^^^\n");
}
void inp(){
	int n,m; scanf("%d%d",&n,&m);
	int bkm = m;
	P * p1 = P1, *p2 = P2;
	for(int i =0 ;i<m;i++){
		scanf("%d%d",&p1[i].A, &p1[i].B);
	}
	int next_m = 0;
	P ans;
	int flag = true;
	while(flag){
		flag = false;
		sort(p1, p1+m);
		P cur = p1[0];
		next_m = 0;
		for(int i = 1;i<m;i++){
			if( getI(cur, p1[i], ans ) ){
				cur = ans;
				flag = true;
			}
			else {
				p2[next_m++] = cur;
				cur = p1[i];
			}
		}
		p2[next_m++] = cur;
		swap(next_m, m);
		swap(p1, p2);
		//pP(p1, m);
	}
	printf("%d",  m );
}
//d.cc by xsthunder at Wed Jul 25 23:18:28 2018

//AC at Wed Jul 25 23:35:41 2018
 
