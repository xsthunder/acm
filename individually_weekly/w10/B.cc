#include<iostream>
#include<iomanip>
using namespace std;
#define iF if(Te)
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;;
	while(t--){
		inp();
	}
	return 0;
}
const int N  	=2e3;
int va [N];
int vo [N];
int dp[N][N];
void inp(){
	int n,v;
	cin>>n>>v;
	for(int i =0;i< n;i++){
		cin>>va[i];
	}
	for(int i =0;i< n;i++){
		cin>>vo[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=v;j++){
			if(j<vo[i]){
				dp[i+1][j]=dp[i][j];
			}
			else dp[i+1][j]=max(dp[i][j],dp[i+1][j-vo[i]]+va[i]);
		}
	}
	pM(dp,n+1,v+2,3);
	cout<<dp[n][v]<<endl;
}
//B.cc
//generated automatically at Sun Apr 30 19:20:07 2017
//by xsthunder

