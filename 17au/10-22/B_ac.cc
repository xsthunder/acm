#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	freopen("B.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
#define X first
#define Y second
const int N = 4000+10;
P ps[N];
struct Ask{
	bool p;int x,y;ll ans;
}ask[N*N/2+2*N],o[N*N/2+2*N];
operator < (Ask a,Ask b){
	if(a.x == b.x){ return a.p>b.p; }
	else return a.x>b.x;
}
ll ans;P ansp;
const int top = 1e6+10;
int bit[top+5];
#define reans(p,q,cnt) if((ll)(p)*(q)*(cnt)>ans)ansp=P(p,q),ans=(ll)(p)*(q)*(cnt)
#define lb(z) (z)&(-z)
void add(int val){
	for(;val<=top;val+=lb(val)){ bit[val]++; }
}
int que(int val){
	int ans=0;
	for(;val;val-=lb(val)){ ans += bit[val]; }
	return ans;
}
void clr(int val){
	for(;val<=top&&bit[val];val+=lb(val)){ bit[val]=0; }
}	
void cdq(int L,int R){
	if(R-L <=1)return ;
	int M = (L+R)>>1;cdq(L,M),cdq(M,R);
	int m = L,r = M,cnt = 0;
	Ask cur;int n=0;
	while(m<M&&r<R){
		if(ask[m]<ask[r]){ cur = ask[m];m++; }
		else { cur = ask[r];r++; }
		if(cur.p){ add(cur.y);n++; }
		else {
			cur.ans += que(cur.y-1);
			reans(cur.x,cur.y,n-cur.ans);
		}
		o[cnt++] = cur;
	}
	while(m<M){
		cur = ask[m];m++;
		if(cur.p){ add(cur.y);n++; }
		else {
			cur.ans += que(cur.y-1);
			reans(cur.x,cur.y,n-cur.ans);
		}
		o[cnt++] = cur;
	}
	while(r<R){
		cur = ask[r];r++;
		if(cur.p){ add(cur.y);n++; }
		else {
			cur.ans += que(cur.y-1);
			reans(cur.x,cur.y,n-cur.ans);
		}
		o[cnt++] = cur;
	}
	for(int i =L,cnt=0;i<R;i++,cnt++){
		ask[i] = o[cnt];
		clr(o[i].y);
	}
}
void inp(){
	int n;
	int acnt=0;
scanf("%d",&n);for(int i=0;i<n;i++){
		scanf("%d%d",&ps[i].X,&ps[i].Y);
		if(ps[i].X>ps[i].Y)swap(ps[i].X,ps[i].Y);
	}
	reans(ps[0].X,ps[0].Y,1);
	for(int i =0;i<n;i++){ ask[acnt++]=Ask{1,ps[i].X,ps[i].Y}; }
	for(int i =0;i<n;i++){ ask[acnt++]=Ask{0,ps[i].X,ps[i].Y,0}; }
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ask[acnt] = Ask{0,min(ps[i].X,ps[j].X),min(ps[i].Y,ps[j].Y),0};
			if(ask[acnt].x>ask[acnt].y)swap(ask[acnt].x,ask[acnt].y);
			acnt++;
		}
	}
	cdq(0,acnt);
	printf("%lld\n",ans);
	printf("%d %d\n",ansp.X,ansp.Y);
}
//B.cc by xsthunder at Sun Oct 22 13:43:24 2017

//AC at Sun Oct 22 15:01:05 2017
 
