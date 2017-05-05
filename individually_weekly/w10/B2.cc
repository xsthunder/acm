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
	cin>>t;
	while(t--){
		inp();
	}
	return 0;
}
const int N =2e3;
int dp[N][N];
int w[N];
int v[N];
void inp(){
	int n,W;
	cin>>n>>W;
	for(int i =0;i<n;i++){
		cin>>v[i];
	}
	for(int i =0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		for(int j =0;j<=W;j++){
			if(j<w[i]){
				dp[i+1][j]=dp[i][j];
			}
			else dp[i+1][j]=max(dp[i][j-w[i]]+v[i],dp[i][j]);
		}
	}
	//pM(dp,n+1,W+1,3);
	cout<<dp[n][W]<<endl;

}
//B2.cc
//generated automatically at Sun Apr 30 19:45:00 2017
//by xsthunder

