#include<cstdio>
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
	freopen("hiho1142.in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
double a,b,c,x,y;
double eps=1e-9;
double cal(double p){
	return sqrt((p-x)*(p-x)+(a*p*p+b*p+c-y)*(a*p*p+b*p+c-y));
}
void inp(){
	if(scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&x,&y)==EOF)exit(0);
	double l = -1e9,r = 1e9,lm=l+(r-l)/3,rm=l+(r-l)/3*2;
	double m = -b/(2*a);
	if(m<x)l=m,r=1e9;
	else l=-1e9,r=m;
	while(l+eps<r){
		lm=l+(r-l)/3,rm=l+(r-l)*2/3;
		if(cal(lm)>cal(rm)){
			l=lm;
		}
		else {
			r=rm;
		}
	}
	printf("%.3f\n",cal(l));
}
//hiho1142.cc by xsthunder at Wed Sep 13 17:36:39 2017

//AC at Fri Sep 15 20:48:21 2017
 
