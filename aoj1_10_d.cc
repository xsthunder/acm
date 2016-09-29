#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
const int N=100+10;
int X[N];
int Y[N];
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	double p3,p2,p1,p4;
	int n;
	p1=0;
	p4=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d", &X[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d", &Y[i]);
	}
	for(int i=0;i<n;i++){
		double tmp=fabs(Y[i]-X[i]);
		p4=max(tmp,p4);
		p1+=tmp;
		p2+=tmp*tmp;
		p3+=tmp*tmp*tmp;
	}
	p2=sqrt(p2);
	p3=pow(p3,1.0/3.0);
	printf("%.8f\n%.8f\n%.8f\n%.8f\n", p1,p2,p3,p4);
	//insert code above
	return 0;
}
//aoj1_10_d.cc

