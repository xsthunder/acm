#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;

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
ll n;
const int N = 2e3;
ll a[N];

void inp(){
	if(!(cin>>n))exit(0);
	n<<=1;
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	pA(a,n,3);
	ll ans  =0;
	n>>=1;
	for(int i =0;i<n;i++){
		ans+= a[(i<<1)+1]-a[i<<1];
	}
	cout<<ans<<endl;
}
//O.cc by xsthunder at Sat Jun  3 12:33:36 2017
