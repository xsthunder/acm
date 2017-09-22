#ainclude<cstdio>
#include<cmath>
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
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
double x1,x2,x3,x4,y1,y2,y3,y4,d,r,p,x5,y5;
const double eps=1e-9;
void inp(){
	scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2);
	p=hypot(x1,y1);
	if(p<eps){ printf("%.7f\n",r*2);return; }
	double co = r*r/p/p;
	x3=x1*co,x4=x2*co,y3=y1*co,y4=y2*co;
	d = hypot((x3+x4)/2,(y3+y4)/2);
	if(d<=r){
		printf("%.7f\n",hypot(x4-x3,y4-y3)*p/r);
	}
	else {
		x5=(x1+x2)/2,y5=(y1+y2)/2;
		co = r/hypot(x5,y5);
		x5*=co,y5*=co;
		printf("%.7f\n",hypot(x5-x1,y5-y1)*2);
	}
}
//hdu6097c.cc by xsthunder at Fri Sep 22 19:55:31 2017

//AC at Fri Sep 22 20:06:53 2017
 
