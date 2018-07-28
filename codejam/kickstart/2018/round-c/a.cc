#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
#define MS(m) memset(m,0,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	freopen("a.in","r",stdin);
#endif
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++){
		printf("Case #%d:", i);
		inp();
	}
	return 0;
}
const int N = 1e3 + 100;
const int NN = 2e3 + 100;
int n;
P ps[N]; int pscnt;
struct E{
	int id;
	int t;
}es[NN];int escnt;
#define X first
#define Y second
vector<int> arr[N];
void ae(int f,int t){
		E & e = es[escnt];
		e.id = pscnt;
		e.t = t;
		arr[f].push_back(escnt);
		//printf("%d %d\n", f,t);
		escnt++;
}
int ig;
bool vis[N];
bool ign(){
	queue<int> q;
	int cnt = 0;
	for(int i = 1;i<=n;i++)vis[ i ] = 0;
	q.push(1);
	while(!q.empty()){
		int cur = q.front();q.pop();
		if( vis[cur] )continue;
		vis[cur] = 1;
		cnt ++;
		for(int i: arr[cur] ){
			const E &e = es[i];
			if( e.id == ig || vis[e.t] )continue;
			//printf(" %d -> %d\n", cur, e.t);
			q.push(e.t);

		}
	}
	return cnt == n;
}
int ans[N];
int cala[N], calb[N], acnt, bcnt;
void cal(){
	int cost = 0;
	bcnt = 0;
	int *ca = cala, * cb = calb;
	while( acnt > 0){
		for(int i = 0;i<acnt;i++){
			int cur = ca[ i ];
			ans[cur] = cost;
			for(int i: arr[cur] ){
				const E &e = es[i];
				if(ans[e.t] < 0){
					cb[ bcnt++ ] = e.t;
				}
			}
		}
		cost ++;
		acnt = 0;
		swap(acnt, bcnt);
		swap(ca, cb);
	}
}
void pV(int i){
	printf("%d :",i);
	for(int x: arr[i]){
		printf("#%d:(%d) ", es[x].id, es[x].t);
	}
	putchar('\n');
}
void inp(){
	MS(ps);MS(es);
	for(int i = 1;i<=n;i++)arr[i].clear();
	pscnt = 1;escnt = 1;
	acnt = 0;bcnt = 0;
	scanf("%d",&n);
	for(int i = 1,f,t;i<=n;i++){
		scanf("%d%d",&f,&t);
		ps[pscnt].X = f,ps[pscnt].Y = t;
		ae(f,t),ae(t,f);
		pscnt++;
	}
	//for(int i = 1;i<=n;i++){ pV(i); }
	for(int i = 1;i<=n;i++)ans[i] = -1;
	for(int i = 1;i<=n;i++){
		ig = i;
		int a = ps[i].X,b = ps[i].Y;
		//printf("%d %d %d\n",a,b, ign());
		if( ign() ){
			cala[ acnt++ ] = a;
			cala[ acnt++ ] = b;
			ans[a] = ans[b] = 0;
		}
	}
	cal();
	for(int i = 1;i<=n;i++)printf(" %d", ans[i]);
	putchar('\n');
}
//a.cc by xsthunder at Sat Jul 28 14:10:07 2018

