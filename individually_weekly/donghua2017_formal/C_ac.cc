#include<iostream>
#include<set>
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
ll a[50];
set<ll > s;
int n;
ll cal(int x){
	ll ans=0;
//	iF cout<<'x'<<x<<endl;
	for(int i = 0 ;i<n;i++){
//		cout<<x;
		if(x&1){//1 for minus
			ans-=a[i];
		}
		else {
			ans+=a[i];
		}
		x>>=1;
	}
//	iF cout<<"ans : "<<ans<<endl;
	return ans;
}
void inp(){
	if(!(cin>>n))exit(0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	s.clear();
	for(int i=0;i<(1<<n);i++){
		s.insert(cal(i));
	}
	cout<<s.size()<<endl;;
}
//C.cc by xsthunder at Sat Jun  3 12:15:02 2017

//AC at Sat Jun  3 12:33:31 2017
 
