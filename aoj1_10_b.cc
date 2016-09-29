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
const double PI=3.141592653589793;
typedef long long int ll;
using namespace std;
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	
	double a,b,ang;
	scanf("%lf%lf%lf", &a,&b,&ang);
	//cout<<ang<<endl;
	ang=ang/180*PI;
//	cout<<ang<<endl;
	printf("%f\n%f\n%f\n", a*b*sin(ang)/2,a+b+sqrt(a*a+b*b-2*a*b*cos(ang)),b*sin(ang));
	//insert code above
	return 0;
}
//aoj1_10_b.cc

