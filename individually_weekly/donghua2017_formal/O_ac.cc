#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
typedef long long ll;
ll a[30000];

void inp(){
	int n;
	int n2;
	if(!(cin>>n))exit(0);
	n2=n*2;
	for(int i =0;i<n2;i++){
		cin>>a[i];
	}
	sort(a,a+n2);
	ll ans=0;
	for(int i =0;i<n;i++){
		ans+=a[i*2+1]-a[i*2];
	}
	cout<<ans<<endl;
}
//O.cc by xsthunder at Sat Jun  3 15:00:13 2017

//AC at Sat Jun  3 15:03:35 2017
 
