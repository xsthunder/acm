#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("at83c.in","r",stdin);
#endif
	inp();
	return 0;
}
void inp(){
	int A,B,C,D,E,F;scanf("%d%d%d%d%d%d",&A,&B,&C,&D,&E,&F);
	double den=0;int up=0,dow=0,a,b,c,d;
	for(c=0;c<=3000;c++){
		if(c*C>F)break;
		for(d=0;d<=3000;d++){
			if(c*C+d*D>F)break;
			for(a=0;a<=30;a++){
				if(a*A*100+c*C+d*D>F)break;
				if(a*A*E>=c*C+d*D){ break; }
				if(double(c*C+d*D)/double(c*C+d*D+a*A*100)){
					up=c*C+d*D;
					dow=c*C+d*D+a*A+100;
					den=(double(up)/double(dow));
					break;
				}
				for(b=0;b<=30;b++){
					if(a*A*100+b*B*100+c+d>F)break;
					if((a*A+b*B)*E>=c+d){ break; }
					den=(double(c*C+d*D)/double(c*C+d*D+a*A*100));
					up=c*C+d*D;
					dow=c*C+d*D+a*A+100;
					break;
				}
			}
		}
	}
}
//	for(a = 0;a<=30;a++){
//		ea=100*a*A;if(ea>F)break;
//		for(b=0;b<=30;b++){
//			eb=ea+100*b*B;if(eb>F)break;
//			for(c=0;c<=3000;c++){
//				ec=eb+c*C;if(ec>F)break;
//				if(c>(eb)*E)break;
//				for(d=0;d<=3000;d++){
//					ed=ec+d*D;if(ed>F)break;
//					if(c+d>(eb)*E)break;
//					if(double(ed-eb)/double(ed)>den){
//						up=ed-eb,dow=ed;
//					}
//				}
//			}
//		}
//	}
printf("%d %d\n",up,dow);
}
//at83c.cc by xsthunder at Sat Sep 16 21:09:29 2017

