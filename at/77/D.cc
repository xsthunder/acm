#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	#include<cassert>
	#define NDEBUG
	const int Te=1;
#else 
	const int Te=0;
#endif
#include<iostream>
#include<unordered_map>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
typedef unordered_map<int,int > US;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	try{
		inp();
	}
	catch(... ){
		IF cout<<"exception";
	}//for compatibility with cygwin c++ runtime
	return 0;
}
US us;
const int N = 2e5;
int dp[N][N];
void init(){
	for(int i =0;i<N;i++){

	}
}
ll c(int n,int r){
	if(n>=r)return dp[n][r];
	return 0;
}
void inp(){
	init();
	int n;
	cin>>n;
	us.reserve(n+1);
	int x;
	int d = 0;
	for(int i=0;i<n+1;i++){
		cin>>x;
		if(us.count(x)){
			d=i-us[x];
			break;
		}
		us[x]=i;
	}
	for(int i =1;i<=n+1;i++){
		cout<<c(n+1,i)-c(n-d,k)<<endl;
	}
}
//D.cc by xsthunder at Sun Jul  2 22:40:33 2017

