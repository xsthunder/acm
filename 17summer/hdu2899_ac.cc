#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
#define log(z) cout<<#z<<' '<<z<<endl;
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
double y;
double f2(double x){
	return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x-y;
}
double f3(double x){
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
const double eps=1e-9;
void inp(){
	scanf("%lf",&y);
	//log(y)
	if(f2(0)>0&&f2(100)>0){puts("0"); return; }
	if(f2(0)<0&&f2(100)<0){puts("100.0000");return;}
	double a1=f2(0),a2=f2(100),d;
	///log(a1)log(a2)
	double l=0,r=100,lm,rm;
	while(l+eps<r){
		lm=l+(r-l)/3,rm=l+(r-l)/3*2;
		if(f3(lm)<f3(rm))r=rm;
		else l=lm;
	}
	printf("%.4f\n",f3(l));
}
//hdu2899.cc by xsthunder at Fri Sep 15 20:48:27 2017

//AC at Fri Sep 15 21:55:42 2017
 
