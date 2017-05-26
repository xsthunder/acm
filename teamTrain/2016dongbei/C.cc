#include<iostream>
#include<set>
#include<cstdlib>
#include<list>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef long long ll;
typedef pair<ll,ll> P;
void inp();
list<P > dc;
ll tolcnt=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i =1;i<=t;i++){
		cout<<"Case #"<<i<<":"<<endl;
		dc.clear();
		inp();
		cout<<tolcnt<<endl;
		for(auto x:dc){
	//		cout<<x.first<<' '<<x.second<<endl;
			for(ll  i= b;i>=x.second;i--){

			}
		}
	}
	return 0;
}
ll a,b,d;
int ju(ll a,ll b,ll c,ll d){
	ll l = b*c;
	ll r = a*d;
	if(l==r)return 0;
	if(l<r)return 1;
	return -1;
}
ll bs(const ll a,const ll b,const ll d){
	ll r,l;
	l = a,r=b;
	r++;
	int cnt=0;
	ll m ;
	while(cnt<40){
		m = (r+l)/2;
		//iF cout<<P(l,r)<<m<<endl;
		if(r==l)break;
		switch(ju(a,b,m,d)){
			case 0:return m;
			case -1:
						 r = m-1;
						 break;
			case 1:
						 l = m;
						 if(l==r-1){
							 if(ju(a,b,r,d)>=0)return r;
							 if(ju(a,b,l,d)>=0)return l;
							 return 0;
						 }
						 break;
		}
		cnt++;
	}
	if(ju(a,b,m,d)==-1)return 0;
	return m;
}
void inp(){
	tolcnt=0;
	cin>>a>>b;
	for(d = b;d>a;d--){
		ll tmp = bs(a,b,d);
		if(tmp>d)break;
		if(tmp==0)break;
		dc.push_front(P(d,tmp));
//		for(int i =1;i<=tmp;i++){
//			s.insert(P(i,d));
//			s.insert(P(d,i));
//		}
	}
}
//C.cc by xsthunder at Tue May 16 18:29:42 2017

