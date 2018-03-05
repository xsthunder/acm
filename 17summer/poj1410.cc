#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<double ,double > P;
void inp();
int main(){
#ifdef XS
	freopen("poj1410.in","r",stdin);
#endif
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int RN = 5;
const double eps = 1e-10;
struct L{
	P a,b;
}sL;
P recP[RN];
#define X first
#define Y second
L l,tmp;

double dcmp(double a){
	if(fabs(a)<eps)return 0;
	if(a<0)return -1;
	return 1;
}
P operator- (P a,P b){ return P (a.X-b.X,a.Y-b.Y); }
double dot (P a,P b){ return a.X*b.X+a.Y*b.Y; }
double cro (P a,P b){ return a.X*b.Y-a.Y*b.X; }
bool eq(P a,P b){
	return dcmp(a.X-b.X)==0&&dcmp(a.Y-b.Y)==0;
}
P A2B(P a,P b){ return ((b)-(a)); }
bool p2se(P a,L l){
	P A=A2B(a,l.a),B=A2B(a,l.b);
	return dcmp(cro(A,B))==0&&dcmp(dot(A,B))<0;
}
bool _inter(L a,L b){
	P m = A2B(a.a,a.b);
	return dcmp(cro(A2B(a.a,b.a),m))*dcmp(cro(A2B(a.a,b.b),m))<0;
}
bool inter(L a,L b){
	return _inter(a,b)&&_inter(b,a);
}
void inp(){
	scanf("%lf%lf%lf%lf",&sL.a.X,&sL.a.Y,&sL.b.X,&sL.b.Y);
	scanf("%lf%lf%lf%lf",&l.a.X,&l.a.Y,&l.b.X,&l.b.Y);
	tmp.a.X=min(l.a.X,l.b.X);
	tmp.a.Y=min(l.a.Y,l.b.Y);
	tmp.b.X=max(l.a.X,l.b.X);
	tmp.b.Y=max(l.a.Y,l.b.Y);
	recP[0]=tmp.a;
	recP[1]=P(l.a.X,l.b.Y);
	recP[2]=tmp.b;
	recP[3]=P(l.b.X,l.a.Y);
	recP[4]=tmp.a;
	// p2p
	int f = 0;
	for(int i=1;i<RN&&!f;i++){
		if(eq(sL.a,recP[i])||eq(sL.b,recP[i])){ f = 1; }
	}
	// recP to se
	for(int i=1;i<RN&&!f;i++){
		if(p2se(recP[i],sL))f=1;
	}
	// seP to recP
	for(int i=1;i<RN&&!f;i++){
		if(p2se(sL.a,L{recP[i],recP[i-1]}))f=1;
		if(p2se(sL.b,L{recP[i],recP[i-1]}))f=1;
	}
	// se 2 se
	for(int i=1;i<RN&&!f;i++){
		if(inter(sL,L{recP[i],recP[i-1]}))f=1;
	}
	puts(f?"T":"F");
}
//poj1410.cc by xsthunder at Mon Oct 16 08:24:52 2017

