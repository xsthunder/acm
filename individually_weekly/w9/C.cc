#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 1e3+500;
int dp[M];
int A[M];
int n;
const int MM=1e5;
void dfs(int cur){
	int m=M;
	if(cur>n)return ;
	for(int i =0;i< cur;i++){
		if(dp[i]>=5){
			m=min(m,dp[i]);
			//cout<<"d"<<i<<endl;
		}
	}
	if(m==M)dp[cur]=dp[0];
	else {
		dp[cur]=m-A[cur];
	}
	dfs(cur+1);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>n){
		if(!n)return 0;
		for(int i =0;i< n;i++){
			cin>>A[i+1];
		}
		sort(A+1,A+n+1);
		memset(dp,0,sizeof(dp));
		cin>>dp[0];
		if(dp[0]<5){
			cout<<dp[0]<<endl;
			continue;
		}
		dfs(1);
		int m =M ;
		for(int i =0;i<=n;i++){
			m=min(dp[i],m);
		}
		cout<<m<<endl;
	}
	return 0;
}
