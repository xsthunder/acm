#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<cmath>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<double ,double > P;
void inp();
int main(){
#ifdef XS
	freopen("poj1556.in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
const int Necnt=20000;
P ps[Necnt];
struct E{ int f,t,n;double d; }es[Necnt];
struct L{ P a,b; }ls[Necnt];
int ecnt,head[Necnt],cnt,lcnt;
const double eps = 1e-12;
int dcmp(double a){
	if(fabs(a)<eps)return 0;
	if(a>0)return 1;
	return -1;
}
#define X first
#define Y second
P operator - (P a,P b){ return P{a.X-b.X,a.Y-b.Y}; } 
double operator * (P a,P b){ return a.X*b.Y-a.Y*b.X; }
#define sq(z) ((z)*(z))
double dist(P a,P b){
	return sqrt(sq(a.X-b.X)+sq(a.Y-b.Y));
}
bool _inter(L l, L m){
	return dcmp(
			((m.a-l.a)*(l.b-l.a))
			*
			((m.b-l.b)*(l.b-l.a))
			)<0
		;
}
bool inter(L l,L m){
	return _inter(l,m)&&_inter(m,l);
}
void ae(int f,int t,double d){
	es[ecnt]=E{f,t,head[f],d};head[f]=ecnt;ecnt++;
}
const double inf = 1e20;
double d[Necnt];
struct Q{ double d;int i; };
bool operator < (Q a,Q b){
	if(a.d==b.d)return a.i<b.i;
	return a.d>b.d;
}
void dij(){
	priority_queue<Q> pq;
	fill(d,d+Necnt,inf);
	pq.push(Q{0.0,0});
	Q q;E e;
	while(!pq.empty()){
		q = pq.top();pq.pop();
		if(dcmp(q.d-d[q.i])<0){
			d[q.i]=q.d;
			if(head[q.i]!=-1)for(e = es[head[q.i]];;e=es[e.n]){
				if((d[e.t]-(q.d+e.d))>0){
					pq.push(Q{q.d+e.d,e.t});
				}
				if(e.n==-1)break;
			}
		}
	}
}
void inp(){
	int n;double x,y;scanf("%d",&n);if(n<0)exit(0);MS(head,-1);
	cnt=0,lcnt=0,ecnt=0;
	ps[cnt++]=P(0.0,5.0);
	P p;
	for(int i=1;i<=n;i++){
		scanf("%lf",&x);
		p = P(x,0);
		scanf("%lf",&y);ps[cnt++]=P(x,y);
		ls[lcnt++]=L{p,ps[cnt-1]};

		scanf("%lf",&y);ps[cnt++]=P(x,y);
		p=P{x,y};

		scanf("%lf",&y);ps[cnt++]=P(x,y);
		ls[lcnt++]=L{p,ps[cnt-1]};

		scanf("%lf",&y);ps[cnt++]=P(x,y);
		p=P{x,y};
		ls[lcnt++]=L{p,P(x,10.0)};

	}
	ps[cnt++]=P(10.0,5.0);
	int s;
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
			s = 1;
			for(int k=0;k<lcnt&&s;k++){
				if(inter(ls[k],L{ps[i],ps[j]})){ s=0; }
			}
			double d = dist(ps[i],ps[j]);
			if(s){ ae(i,j,d);ae(j,i,d); }
		}
	}
	dij();
	printf("%.2f\n",d[cnt-1]);
}
//poj1556.cc by xsthunder at Wed Oct 11 09:22:55 2017

//AC at Sun Oct 15 07:59:30 2017
 
