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
const int N=1000+5;
double A[N];
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	int n;
	while(scanf("%d",&n)!=EOF&&n){
	double sum =0;
	double ans=0;
	for(int i=0;i<n;i++){
		scanf("%lf",&A[i]);
		sum+=A[i];
	}
	sum/=n;
//	cout<<sum<<endl;
	for(int i=0;i<n;i++){
		ans+=(A[i]-sum)*(A[i]-sum);
	}
	ans=sqrt(ans/n);
	printf("%f\n",ans);
	}
	//insert code above
	return 0;
}
//aoj1_10_c.cc

