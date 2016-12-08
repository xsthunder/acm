const bool test=0;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<double  , int > point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
void sol(){
}
int main()
{
	while(1){
		vector<point > V;
		vector<point > V2;
		for(int c=0;c<2;c++){
			for(int i=0;i<2;i++){
				double x,y;
				if(scanf("%lf%lf",&x,&y)==EOF)return 0;
				V.push_back(make_pair(x,c));
				V2.push_back(make_pair(y,c));
			}
		}
		getchar();
		sort(V.begin(),V.end());
		sort(V2.begin(),V2.end());
		double area=0;
		double x1=V[2].first;
		double x2=V[1].first;
		double y1=V2[2].first;
		double y2=V2[1].first;
		area=(x1-x2)*(y1-y2);
		area=fabs(area);
		int status=0;
		for(auto x:V){
			status<<=1;
			status|=x.second;
		}
		int status2=0;
		for(auto x:V2){
			status<<=1;
			status|=x.second;
		}
		IF printf("status %d\n",status);
		if(status==12||status==3||status2==12||status2==3)area=0;
		printf("%.2lf\n",area);
	}
	return 0;
}
//hdu2056a.cc
//generated automatically at Wed Nov 30 21:23:12 2016
//by xsthunder

